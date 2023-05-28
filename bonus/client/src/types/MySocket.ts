import type { Socket } from "socket.io-client";
import type {
  ClientToServerEvents,
  ServerToClientEvents,
} from "../../../server/src/types/ws";

type MySocket = Socket<ServerToClientEvents, ClientToServerEvents>;

export default MySocket;
