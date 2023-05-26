import { Server } from "socket.io";
import {
  ClientToServerEvents,
  InterServerEvents,
  ServerToClientEvents,
  SocketData,
} from "./types/ws";
import { getChampions } from "./champions";
import { spawn } from "child_process";
import ReadLine from "readline";

const COREWAR_BIN = "../corewar/corewar";

const io = new Server<
  ClientToServerEvents,
  ServerToClientEvents,
  InterServerEvents
>(3000, {
  cors: {
    allowedHeaders: "*",
    origin: "*",
  },
});

const clients = new Map<string, SocketData>();

io.on("connection", (socket) => {
  clients.set(socket.id, { isFighting: false });

  socket.on("getChampions", () => {
    try {
      socket.emit("setChampions", getChampions());
    } catch (e) {
      socket.emit("error", (e as Error).message);
    }
  });

  socket.on("requestFight", (champions) => {
    let client = clients.get(socket.id)!;

    if (client.isFighting) {
      socket.emit("error", "Already fighting");
      return;
    }

    client.isFighting = true;
    client.fightProc = spawn(
      COREWAR_BIN,
      champions.map((c) => c.path)
    );

    const rl = ReadLine.createInterface({
      input: client.fightProc.stderr,
    });

    client.fightProc.stdout.on("data", () => {});

    rl.on("line", (line) => {
      console.log(JSON.parse(line));
    });


    client.fightProc.on("close", (code) => {
      if (code !== 0) {
        console.log("fight failed");
      }

      console.log(`child process exited with code ${code}`);
      client.isFighting = false;
      client.fightProc = undefined;
    });
  });

  socket.on("disconnect", () => {
    let client = clients.get(socket.id)!;

    if (client.isFighting) {
      console.log("cleaned up fight" + socket.id);
      client.fightProc?.kill();
    }

    clients.delete(socket.id);
  });
});
