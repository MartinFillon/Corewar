import { useState } from "react";
import Header from "./components/Header";
import SetupFight from "./components/SetupFight";
import Arena from "./components/Arena";
import Champion from "../../server/src/types/champion";
import CurrentView from "./types/CurrentView";

const App = () => {
  const [currentView, setCurrentView] = useState<CurrentView>("setup");
  const [arenaChamps, setArenaChamps] = useState<Champion[]>([]);

  return (
    <>
      <Header currentView={currentView} />

      <main className="flex flex-col min-h-screen items-center">
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
            fight: (
              <Arena
                champions={arenaChamps}
                onExit={() => {
                  setArenaChamps([]);
                  setCurrentView("setup");
                }}
              />
            ),
          }[currentView]
        }
      </main>
    </>
  );
};

export default App;
