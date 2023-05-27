import Fighter from "../../types/Fighter";

type WinnerProps = {
  fighters: Fighter[];
  winnerPid: number;
  onExit: () => void;
};

const Winner = ({ fighters, winnerPid, onExit }: WinnerProps) => (
  <div className="flex flex-col items-center">
    <div className="alert alert-success mb-2">
      {`${fighters[winnerPid].name}(${winnerPid})`} won the fight!
    </div>
    <button className="btn btn-link" onClick={onExit}>
      Back to setup
    </button>
  </div>
);

export default Winner;
