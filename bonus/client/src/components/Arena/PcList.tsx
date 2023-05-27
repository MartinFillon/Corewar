import Fighter from "../../types/Fighter";
import {
  CANVAS_WIDTH,
  CELL_PADDING,
  CELL_SIZE,
  MEM_WIDTH,
} from "./utils/constants";

type PcListProps = {
  fighters: Fighter[];
  canvasRef: React.RefObject<HTMLCanvasElement>;
};

const PcList = ({ fighters, canvasRef }: PcListProps) => {
  const width = canvasRef.current
    ? parseInt(getComputedStyle(canvasRef.current).width)
    : CANVAS_WIDTH;
  const ratio = width / CANVAS_WIDTH;

  return (
    <>
      {fighters.map((fighter, index) => (
        <div
          key={index}
          className="absolute border rounded-sm border-black"
          style={{
            width: (CELL_SIZE + CELL_PADDING * 2) * ratio + 1 + "px",
            height: (CELL_SIZE + CELL_PADDING * 2) * ratio + 1 + "px",
            left:
              ((fighter.pc % MEM_WIDTH) * (CELL_SIZE + CELL_PADDING) -
                CELL_PADDING -
                1) *
                ratio +
              "px",
            top:
              (Math.floor(fighter.pc / MEM_WIDTH) * (CELL_SIZE + CELL_PADDING) -
                CELL_PADDING -
                1) *
                ratio +
              "px",
          }}
        ></div>
      ))}
    </>
  );
};

export default PcList;
