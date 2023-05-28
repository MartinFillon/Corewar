import Champion from "../../../../server/src/types/champion";

type AddChampionProps = {
  champions: Champion[];
  onAdd: (champion: Champion) => void;
  canAdd: boolean;
};

const AddChampion = ({ champions, onAdd, canAdd }: AddChampionProps) => {
  return (
    <div className="dropdown dropdown-end">
      <label
        tabIndex={0}
        className={`btn btn-secondary ${canAdd ? "" : "btn-disabled"} m-1`}
      >
        Add champion
      </label>

      <ul
        tabIndex={0}
        className="dropdown-content menu p-2 shadow bg-base-200 rounded-box w-52"
      >
        {champions.map((champion, index) => (
          <li key={index} value={index}>
            <a onClick={() => canAdd && onAdd(champion)}>{champion.name}</a>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default AddChampion;
