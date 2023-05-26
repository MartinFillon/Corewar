import { useState } from "react";
import Header from "./components/Header";
import SetupFight from "./components/SetupFight";
import Arena from "./components/Arena";
import Champion from "../../server/src/types/champion";

type CurrentView = "setup" | "fight";

const App = () => {
  const [currentView, setCurrentView] = useState<CurrentView>("setup");
  const [arenaChamps, setArenaChamps] = useState<Champion[]>([]);

  return (
    <main className="flex flex-col min-h-screen items-center">
      <Header />

      {
        {
          setup: (
            <SetupFight
              onStart={(champs) => {
                setArenaChamps(champs);
                setCurrentView("fight");
              }}
            />
          ),
          fight: <Arena champions={arenaChamps} />,
        }[currentView]
      }
    </main>
  );
};

export default App;
