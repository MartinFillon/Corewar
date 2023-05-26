import { readdirSync } from "fs";
import { join } from "path";
import Champion from "./types/champion";
import corewarHeaderParser from "../addons";

const CHAMPS_DIR = "./champions";

export const getChampions = (): Champion[] => {
  const champions = readdirSync(CHAMPS_DIR);

  return champions.map((champ) => {
    let path = join(CHAMPS_DIR, champ);

    let { name, comment } = corewarHeaderParser.readHeader(path);

    return { name, comment, path };
  });
};
