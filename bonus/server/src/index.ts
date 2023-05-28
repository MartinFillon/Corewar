import { Server } from "socket.io";
import {
  ClientToServerEvents,
  InterServerEvents,
  ServerToClientEvents,
  SocketData,
} from "./types/ws";
import { checkValidChampions, getChampions } from "./champions";
import { spawn } from "child_process";
import ReadLine from "readline";
import { streamUpdates } from "./fight";

const COREWAR_BIN = "./corewar";

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

    try {
      checkValidChampions(champions);
    } catch (e) {
      socket.emit("error", (e as Error).message);
      return;
    }

    client.isFighting = true;
    client.fightProc = spawn(
      COREWAR_BIN,
      champions.map((c) => c.path)
    );

    client.fightProc.on("error", (e) => {
      socket.emit("error", (e as Error).message);
      client.isFighting = false;
      client.fightProc = undefined;
    });

    client.fightProc.stdout.on("data", () => {});

    const rl = ReadLine.createInterface({
      input: client.fightProc.stderr,
    });

    streamUpdates(rl, socket, 5);

    client.fightProc.on("close", () => {
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
