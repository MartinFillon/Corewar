import { CELL_PADDING, CELL_SIZE, COLORS, MEM_HEIGHT } from "./constants";

const drawMemoryAccess = (
  address: number,
  pid: number,
  size: number,
  canvas: HTMLCanvasElement
) => {
  const ctx = canvas.getContext("2d");

  if (!ctx) return;

  ctx.beginPath();
  ctx.fillStyle = COLORS[pid - 1];

  for (let j = 0; j < size; j++) {
    const x = (address + j) % MEM_HEIGHT;
    const y = Math.floor((address + j) / MEM_HEIGHT);

    ctx.fillRect(
      x * (CELL_SIZE + CELL_PADDING),
      y * (CELL_SIZE + CELL_PADDING),
      CELL_SIZE,
      CELL_SIZE
    );
  }
};

export default drawMemoryAccess;
