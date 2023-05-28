export default require("./build/Release/corewar_read_header.node") as {
  readHeader: (filePath: string) => {
    name: string;
    comment: string;
    progSize: number;
  };
};
