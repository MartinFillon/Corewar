import { useEffect, useRef, useState } from "react";
import Champion from "../../../../server/src/types/champion";
import { useSocketCtx } from "../../contexts/SocketContext";
import Fighter from "../../types/Fighter";
import assignFighterAddresses from "./utils/assignFighterAddresses";
import { CANVAS_HEIGHT, CANVAS_WIDTH } from "./utils/constants";
import drawFighters from "./utils/drawFighters";
import drawMemory from "./utils/drawMemory";
import drawMemoryAccess from "./utils/drawMemoryAccess";
import LiveScore from "./LiveScore";
import Winner from "./Winner";
import Error from "./Error";
import PcList from "./PcList";

type ArenaProps = {
  champions: Champion[];
  onExit: () => void;
};

const Arena = ({ champions, onExit }: ArenaProps) => {
  const socket = useSocketCtx();
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const [error, setError] = useState("");
  const [nbCycles, setNbCycles] = useState<number>(0);
  const [cycleToDie, setCycleToDie] = useState<number>(0);
  const [winnerPid, setWinnerPid] = useState<number>(-1);
  const [fighters, setFighters] = useState<Fighter[]>(
    champions.map((champion) => ({
      ...champion,
      nbFork: 0,
      address: 0,
      instructionCount: 0,
      pc: 0,
      live: 0,
      dead: false,
    }))
  );

  useEffect(() => {
    assignFighterAddresses(fighters);

    if (canvasRef.current) {
      drawMemory(canvasRef.current);
      drawFighters(fighters, canvasRef.current);
    }

    socket.on("error", (error) => setError(error));

    socket.on("pushFightUpdate", (update) => {
      switch (update.action) {
        case "fork":
          setFighters((fighters) => {
            const newFighters = [...fighters];
            newFighters[update.pid - 1].nbFork++;
            return newFighters;
          });
          break;
        case "memory":
          if (canvasRef.current) {
            drawMemoryAccess(
              update.address,
              update.pid,
              update.size,
              canvasRef.current
            );
          }
          break;
        case "live":
          setFighters((fighters) => {
            const newFighters = [...fighters];
            newFighters[update.pid - 1].live++;
            return newFighters;
          });
          break;
        case "cycle":
          setNbCycles(update.nb_cycle);
          break;
        case "winner":
          if (update.pid > 0 && update.pid <= fighters.length) {
            setWinnerPid(update.pid - 1);
          }
          break;
        case "dead":
          setFighters((fighters) => {
            const newFighters = [...fighters];
            newFighters[update.pid - 1].dead = true;
            return newFighters;
          });
          break;
        case "exec":
          setFighters((fighters) => {
            const newFighters = [...fighters];
            newFighters[update.pid - 1].pc = update.pc;
            newFighters[update.pid - 1].instructionCount++;
            return newFighters;
          });
          break;
        case "cycle_to_die":
          setCycleToDie(update.cycle_to_die);
          break;
      }
    });

    socket.emit("requestFight", champions);

    const beforeUnload = (event: BeforeUnloadEvent) => {
      event.returnValue = "Are you sure you want to leave?";
    };
    window.addEventListener("beforeunload", beforeUnload);
    return () => {
      socket.off("error");
      socket.off("pushFightUpdate");
      window.removeEventListener("beforeunload", beforeUnload);
    };
  }, [socket, champions]);

  if (error) {
    return <Error error={error} onExit={onExit} />;
  }

  return (
    <div className="flex flex-col items-center mt-8 pb-52">
      {winnerPid !== -1 && (
        <Winner fighters={fighters} winnerPid={winnerPid} onExit={onExit} />
      )}

      <div className="relative w-11/12">
        <canvas
          ref={canvasRef}
          className="border-base-300 bg-base-300 w-full"
          width={CANVAS_WIDTH}
          height={CANVAS_HEIGHT}
        />

        <PcList fighters={fighters} canvasRef={canvasRef} />
      </div>

      <LiveScore
        fighters={fighters}
        nbCycles={nbCycles}
        cycleToDie={cycleToDie}
      />
    </div>
  );
};

export default Arena;
