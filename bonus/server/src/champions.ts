import { readdirSync } from "fs";
import { join } from "path";
import Champion from "./types/champion";
import corewarHeaderParser from "../addons";

const CHAMPS_DIR = "./champions";

export const getChampions = (): Champion[] => {
  const champions = readdirSync(CHAMPS_DIR);

  return champions.map((champ) => {
    let path = join(CHAMPS_DIR, champ);

    let { name, comment, progSize } = corewarHeaderParser.readHeader(path);

    return { name, comment, path, size: progSize, address: 0 };
  });
};

export const checkValidChampions = (champions: Champion[]) => {
  const validChampions = getChampions();

  for (let champion of champions) {
    if (validChampions.find((c) => c.path === champion.path) === undefined) {
      throw new Error("Invalid champion");
    }
  }
};
