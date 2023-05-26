import { ChildProcessWithoutNullStreams } from "child_process";
import Champion from "./champion";

export interface ServerToClientEvents {
  error: (message: string) => void;
  setChampions: (champions: Champion[]) => void;
  // setFight: (fightPID: number) => void;
  // setFightStatus: (isFighting: boolean) => void;
}

export interface ClientToServerEvents {
  getChampions: () => void;
  requestFight: (champions: Champion[]) => void;
}

export interface InterServerEvents {
  ping: () => void;
}

export interface SocketData {
  fightProc?: ChildProcessWithoutNullStreams;
  isFighting: boolean;
}
