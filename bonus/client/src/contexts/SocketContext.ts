import { createContext, useContext } from "react";
import MySocket from "../types/MySocket";

const SocketContext = createContext<MySocket>({} as MySocket);

export const useSocketCtx = () => useContext(SocketContext);

export default SocketContext;
