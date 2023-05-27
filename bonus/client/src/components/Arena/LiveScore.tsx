import Fighter from "../../types/Fighter";

type LiveScoreItemProps = {
  fighters: Fighter[];
  fighter: Fighter;
};

const LiveScoreItem = ({ fighter, fighters }: LiveScoreItemProps) => (
  <div
    className={`flex flex-col bg-base-100 rounded-md p-2 m-2 ${
      fighter.dead ? "opacity-40" : ""
    }`}
  >
    <div className="flex items-center mb-1">
      <div className="ml-auto">{fighter.name}</div>

      <kbd className="kbd kbd-xs text-success mx-2">{fighter.live}</kbd>

      <progress
        className="progress progress-success w-80 bg-base-100"
        value={fighter.live}
        max={Math.max(...fighters.map((fighter) => fighter.live)) + 100}
      />
    </div>

    <div className="flex flex-wrap gap-1">
      <div className="tooltip" data-tip="number of forks of the program">
        <kbd className="kbd kbd-xs text-info">fork: {fighter.nbFork}</kbd>
      </div>

      <div className="tooltip" data-tip="number of executed instructions">
        <kbd className="kbd kbd-xs text-accent">
          iCount: {fighter.instructionCount}
        </kbd>
      </div>

      <div className="tooltip" data-tip="program counter">
        <kbd className="kbd kbd-xs text-warning">pc: {fighter.pc}</kbd>
      </div>

      {fighter.dead && <kbd className="kbd kbd-xs text-error">dead</kbd>}
    </div>
  </div>
);

type LiveScoreProps = {
  fighters: Fighter[];
  nbCycles: number;
};

const LiveScore = ({ fighters, nbCycles }: LiveScoreProps) => (
  <div className="collapse w-full fixed bottom-0 bg-base-300 collapse-arrow">
    <input type="checkbox" defaultChecked />

    <h2 className="collapse-title text-center">
      <kbd className="kbd kbd-md">Live data</kbd>
    </h2>

    <div className="collapse-content">
      <div className="text-lg text-center mb-4">
        cycles: <kbd className="kbd kbd-sm mr-2">{nbCycles}</kbd>
      </div>

      <div className="flex flex-wrap px-4 justify-center">
        {fighters.map((fighter, i) => (
          <LiveScoreItem key={i} fighter={fighter} fighters={fighters} />
        ))}
      </div>
    </div>
  </div>
);

export default LiveScore;
