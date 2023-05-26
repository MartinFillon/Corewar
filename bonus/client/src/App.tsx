import { useEffect, useRef } from "react";
import { io } from "socket.io-client";

function App() {
  const socketRef = useRef(io("http://localhost:3000"));

  useEffect(() => {
    socketRef.current.on("noArg", () => {
      console.log("noArg");
    });

    console.log(socketRef.current);
  }, []);

  return (
    <main className="flex h-screen items-center justify-around">
      <button
        className="text-xl border rounded-lg p-2"
        onClick={() => {
          socketRef.current.emit("hello");
        }}
      >
        start
      </button>
    </main>
  );
}

export default App;
