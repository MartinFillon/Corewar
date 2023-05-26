import { useEffect, useState } from "react";
import Champion from "../../../server/src/types/champion";
import { useSocketCtx } from "../contexts/SocketContext";

const useChampions = () => {
  const socket = useSocketCtx();
  const [champions, setChampions] = useState<Champion[]>([]);
  const [error, setError] = useState("");

  const refetch = () => {
    socket.emit("getChampions");
    socket.once("setChampions", (data) => setChampions(data));
    socket.once("error", (e) => setError(e));
  };

  useEffect(() => {
    refetch();
  }, []);

  return [champions, error, refetch] as const;
};

export default useChampions;
