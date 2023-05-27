import { CSSProperties, useEffect, useRef, useState } from "react";
import { io } from "socket.io-client";
import SocketContext from "../contexts/SocketContext";
import MySocket from "../types/MySocket";

type ConnectionErrorProps = {
  onRetry: () => void;
};

const ConnectionError = ({ onRetry }: ConnectionErrorProps) => (
  <div className="flex flex-col min-h-screen bg-base-100 justify-center items-center">
    <div className="alert alert-error shadow-lg w-48 mb-4">
      <div>
        <svg
          xmlns="http://www.w3.org/2000/svg"
          className="stroke-current flex-shrink-0 h-6 w-6"
          fill="none"
          viewBox="0 0 24 24"
        >
          <path
            strokeLinecap="round"
            strokeLinejoin="round"
            strokeWidth="2"
            d="M10 14l2-2m0 0l2-2m-2 2l-2-2m2 2l2 2m7-2a9 9 0 11-18 0 9 9 0 0118 0z"
          />
        </svg>
        <span>Connection error</span>
      </div>
    </div>

    <button className="btn btn-sm" onClick={onRetry}>
      Retry
    </button>
  </div>
);

const ConnectionLoading = () => (
  <div className="flex flex-col min-h-screen bg-base-100 justify-center items-center">
    <div
      className="radial-progress animate-spin"
      style={{ "--value": "80" } as CSSProperties}
    ></div>
  </div>
);

type ConnectStatus = "connecting" | "connected" | "pending_connect" | "error";

const SocketProvider = ({ children }: { children: JSX.Element }) => {
  const socket = useRef<MySocket>(
    io(import.meta.env.VITE_SOCKET_URL, { autoConnect: false })
  );
  const [status, setStatus] = useState<ConnectStatus>("pending_connect");

  useEffect(() => {
    if (status !== "pending_connect") return;

    socket.current.connect();
    setStatus("connecting");
    socket.current.once("connect", () => setStatus("connected"));
    socket.current.once("connect_error", () => setStatus("error"));
  }, [status]);

  switch (status) {
    case "error":
      return <ConnectionError onRetry={() => setStatus("pending_connect")} />;

    case "connecting":
      return <ConnectionLoading />;

    case "connected":
      return (
        <SocketContext.Provider value={socket.current}>
          {children}
        </SocketContext.Provider>
      );

    default:
      return null;
  }
};

export default SocketProvider;
