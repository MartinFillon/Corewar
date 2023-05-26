import ThemeSwitch from "./ThemeSwitch";

const Header = () => (
  <div className="navbar bg-base-100">
    <div className="flex-1">
      <a className="btn btn-ghost normal-case text-xl">Corewar</a>
    </div>
    <div className="flex-none">
      <ThemeSwitch />
    </div>
  </div>
);

export default Header;
