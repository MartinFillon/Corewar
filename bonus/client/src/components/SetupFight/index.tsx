import { useState } from "react";
import useChampions from "../../hooks/useChampions";
import Champion from "../../../../server/src/types/champion";
import AddChampion from "./AddChampion";
import ChampionList from "./ChampionList";

type SetupFightProps = {
  onStart: (champions: Champion[]) => void;
};

const SetupFight = ({ onStart }: SetupFightProps) => {
  const [champions, champLoadError] = useChampions();
  const [pipeline, setPipeline] = useState<Champion[]>([]);

  if (champLoadError) {
    return <div>failed to load champions</div>;
  }

  return (
    <div className="flex flex-col items-center">
      <h1 className="text-2xl mb-4">Setup arena</h1>

      <AddChampion
        champions={champions}
        onAdd={(champ) => {
          setPipeline([...pipeline, champ]);
        }}
        canAdd={pipeline.length < 4}
      />

      <ChampionList
        pipeline={pipeline}
        onRemove={(idx) => {
          setPipeline((p) => p.filter((_, i) => i !== idx));
        }}
      />

      {pipeline.length >= 2 ? (
        <button className="btn btn-primary" onClick={() => onStart(pipeline)}>
          Start fight
        </button>
      ) : (
        <div className="alert alert-info shadow-lg">
          <div>
            <svg
              xmlns="http://www.w3.org/2000/svg"
              fill="none"
              viewBox="0 0 24 24"
              className="stroke-current flex-shrink-0 w-6 h-6"
            >
              <path
                strokeLinecap="round"
                strokeLinejoin="round"
                strokeWidth="2"
                d="M13 16h-1v-4h-1m1-4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z"
              ></path>
            </svg>
            <span>At least 2 champions are required to start the fight</span>
          </div>
        </div>
      )}
    </div>
  );
};

export default SetupFight;
