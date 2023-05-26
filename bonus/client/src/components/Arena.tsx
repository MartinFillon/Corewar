import { useEffect } from "react";
import Champion from "../../../server/src/types/champion";
import { useSocketCtx } from "../contexts/SocketContext";

type ArenaProps = {
  champions: Champion[];
};

const Arena = ({ champions }: ArenaProps) => {
  const socket = useSocketCtx();

  useEffect(() => {
    socket.emit("requestFight", champions);

    socket.once("error", (error: string) => {
      console.error(error);
    });

    const beforeUnload = (event: BeforeUnloadEvent) => {
      event.returnValue = "Are you sure you want to leave?";
    };

    window.addEventListener("beforeunload", beforeUnload);

    return () => {
      window.removeEventListener("beforeunload", beforeUnload);
    };
  }, [socket, champions]);

  return (
    <div>
      <h1>Arena</h1>
    </div>
  );
};

export default Arena;
