import { useEffect } from "react";
import useLocalStorage from "./useLocalStorage";
import Theme from "../types/Theme";

const useTheme = () => {
  const [theme, setTheme] = useLocalStorage<Theme>("theme", "light");

  const applyTheme = (theme: Theme) => {
    const root = window.document.documentElement;
    root.setAttribute("data-theme", theme);
  };

  useEffect(() => {
    applyTheme(theme);
  }, [theme]);

  return [theme, setTheme] as const;
};

export default useTheme;
