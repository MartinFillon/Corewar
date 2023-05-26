import { useRef } from "react";
import { io } from "socket.io-client";
import SocketContext from "../contexts/SocketContext";
import MySocket from "../types/MySocket";

const SOCKET_URL = "http://localhost:3000";

const SocketProvider = ({ children }: { children: JSX.Element }) => {
  const socket = useRef<MySocket>(io(SOCKET_URL));

  return (
    <SocketContext.Provider value={socket.current}>
      {children}
    </SocketContext.Provider>
  );
};

export default SocketProvider;
