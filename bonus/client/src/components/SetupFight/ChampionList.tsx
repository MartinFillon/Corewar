import Champion from "../../../../server/src/types/champion";
import humanFileSize from "../../utils/humanFileSize";

type ChampionListProps = {
  pipeline: Champion[];
  onRemove: (champion_idx: number) => void;
};

const ChampionList = ({ pipeline, onRemove }: ChampionListProps) => (
  <div className="flex flex-wrap justify-center max-w-6xl p-2">
    {pipeline.map((item, index) => (
      <div className="card w-72 m-4 bg-base-300 shadow-xl" key={index}>
        <div className="card-body">
          <h2 className="card-title">{item.name}</h2>

          <div className="flex flex-wrap gap-1 justify-between items-center font-mono">
            <small className="badge badge-sm whitespace-nowrap">
              {item.path.length > 15 ? `...${item.path.slice(-15)}` : item.path}
            </small>

            <small className="badge badge-sm">{humanFileSize(item.size)}</small>
          </div>

          <p className="text-lg">{item.comment}</p>

          <div className="card-actions justify-end">
            <button
              className="btn btn-sm btn-error"
              onClick={() => {
                onRemove(index);
              }}
            >
              Remove
            </button>
          </div>
        </div>
      </div>
    ))}
  </div>
);

export default ChampionList;
