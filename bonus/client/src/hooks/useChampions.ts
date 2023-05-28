import { useCallback, useEffect, useState } from "react";
import Champion from "../../../server/src/types/champion";
import { useSocketCtx } from "../contexts/SocketContext";

const useChampions = () => {
  const socket = useSocketCtx();
  const [champions, setChampions] = useState<Champion[]>([]);
  const [error, setError] = useState("");
  const refetch = useCallback(() => socket.emit("getChampions"), [socket]);

  useEffect(() => {
    socket.on("setChampions", (data) => setChampions(data));
    socket.on("error", (e) => setError(e));

    refetch();

    return () => {
      socket.off("setChampions");
      socket.off("error");
    };
  }, [socket, setChampions, setError, refetch]);

  return [champions, error, refetch] as const;
};

export default useChampions;
