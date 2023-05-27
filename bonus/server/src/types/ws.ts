import { ChildProcessWithoutNullStreams } from "child_process";
import Champion from "./champion";
import { FightUpdate } from "./fight";

export interface ServerToClientEvents {
  error: (message: string) => void;
  setChampions: (champions: Champion[]) => void;
  pushFightUpdate: (update: FightUpdate) => void;
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
