import CurrentView from "../../types/CurrentView";
import ThemeSwitch from "./ThemeSwitch";

type HeaderProps = {
  currentView: CurrentView;
};

const Header = ({ currentView }: HeaderProps) => (
  <div className="navbar bg-base-100">
    <div className="navbar-start">
      <a className="btn btn-ghost normal-case text-xl">Corewar</a>
    </div>

    <div className="navbar-center">
      <a className="btn btn-ghost text-xl">{currentView}</a>
    </div>

    <div className="navbar-end">
      <ThemeSwitch />
    </div>
  </div>
);

export default Header;
