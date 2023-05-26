import { Server } from "socket.io";
import {
  ClientToServerEvents,
  InterServerEvents,
  ServerToClientEvents,
  SocketData,
} from "./types/ws";

const io = new Server<
  ClientToServerEvents,
  ServerToClientEvents,
  InterServerEvents,
  SocketData
>(3000, {
  cors: {
    allowedHeaders: "*",
    origin: "*",
  },
});

const clients = new Map<string, SocketData>();

io.on("connection", (socket) => {
  clients.set(socket.id, { name: "John", age: 20 });

  socket.on("hello", () => {
    console.log(clients.get(socket.id));
  });

  socket.on("disconnect", () => {
    clients.delete(socket.id);
  });
});
