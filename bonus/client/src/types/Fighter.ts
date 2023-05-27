import Champion from "../../../server/src/types/champion";

type Fighter = {
  live: number;
  dead: boolean;
  nbFork: number;
  pc: number;
  instructionCount: number;
} & Champion;

export default Fighter;
