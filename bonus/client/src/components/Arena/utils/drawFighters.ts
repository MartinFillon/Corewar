import Fighter from "../../../types/Fighter";
import { CELL_PADDING, CELL_SIZE, COLORS, MEM_WIDTH } from "./constants";

const drawFighters = (fighters: Fighter[], canvas: HTMLCanvasElement) => {
  const ctx = canvas.getContext("2d");

  if (!ctx) return;

  ctx.beginPath();

  for (let i = 0; i < fighters.length; i++) {
    const champion = fighters[i];
    ctx.fillStyle = COLORS[i];

    for (let j = 0; j < champion.size; j++) {
      const x = (champion.address + j) % MEM_WIDTH;
      const y = Math.floor((champion.address + j) / MEM_WIDTH);

      ctx.fillRect(
        x * (CELL_SIZE + CELL_PADDING),
        y * (CELL_SIZE + CELL_PADDING),
        CELL_SIZE,
        CELL_SIZE
      );
    }
  }
};

export default drawFighters;
