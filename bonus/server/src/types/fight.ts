export type FightUpdate =
  | { action: "fork"; pid: number }
  | { action: "live"; pid: number }
  | {
      action: "memory";
      pid: number;
      address: number;
      size: number;
    }
  | { action: "cycle"; nb_cycle: number }
  | { action: "winner"; pid: number }
  | { action: "dead"; pid: number }
  | { action: "exec"; pid: number; pc: number };
