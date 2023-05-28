import { CELL_PADDING, CELL_SIZE, MEM_SIZE, MEM_WIDTH } from "./constants";

const drawMemory = (canvas: HTMLCanvasElement) => {
  const ctx = canvas.getContext("2d");

  if (!ctx) return;

  ctx.beginPath();
  ctx.fillStyle = "#3D4451";

  for (let j = 0; j < MEM_SIZE; j++) {
    const x = j % MEM_WIDTH;
    const y = Math.floor(j / MEM_WIDTH);

    ctx.fillRect(
      x * (CELL_SIZE + CELL_PADDING),
      y * (CELL_SIZE + CELL_PADDING),
      CELL_SIZE,
      CELL_SIZE
    );
  }
};

export default drawMemory;
