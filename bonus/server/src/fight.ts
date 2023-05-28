import ReadLine from "readline";
import {
  ClientToServerEvents,
  InterServerEvents,
  ServerToClientEvents,
} from "./types/ws";
import { Socket } from "socket.io";

export const streamUpdates = async (
  rl: ReadLine.Interface,
  socket: Socket<
    ClientToServerEvents,
    ServerToClientEvents,
    InterServerEvents,
    any
  >,
  delay: number
) => {
  for await (const line of rl) {
    try {
      const update = JSON.parse(line);
      socket.emit("pushFightUpdate", update);
    } catch (_) {
      socket.emit("error", line);
    }

    await new Promise((r) => setTimeout(r, delay));
  }
};
