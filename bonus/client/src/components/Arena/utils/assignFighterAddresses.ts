import Fighter from "../../../types/Fighter";
import { MEM_SIZE } from "./constants";

const assignFighterAddresses = (fighters: Fighter[]) => {
  const gap = MEM_SIZE / fighters.length;

  for (let i = 0; i < fighters.length; i++) {
    fighters[i].address = i * gap;
    fighters[i].pc = i * gap;
  }
};

export default assignFighterAddresses;
