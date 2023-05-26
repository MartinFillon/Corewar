#!/bin/env python3

import argparse
import os
import subprocess as sp
import sys


class Parser:
    def __init__(self):
        self.parser = argparse.ArgumentParser(prog="Corewar Tester")
        self.parser.add_argument("-d", "--directory", type=str,
                                 help="Path to the directory containing the \".cor\" files", required=True)

    def parse_args(self) -> dict:
        return {k: v for k, v in self.parser.parse_args()._get_kwargs()}


class Tester:
    directory: str
    files: list[str]
    failed: int
    passed: int

    def __init__(self, directory: str):
        self.directory = directory
        self.files = [file for file in os.listdir(directory) if file.endswith(".cor")]
        self.files = [os.path.join(directory, file) for file in self.files]
        self.failed = 0
        self.passed = 0

    def test(self) -> None:
        for file in self.files:
            for file2 in self.files:
                print("Testing: {} & {}", file, file2)
                self.run_test(file, file2)
        print("Passed: {}".format(self.passed))
        print("Failed: {}".format(self.failed))

    def run_test(self, file1: str, file2: str) -> None:
        try:
            proc = sp.Popen(["./corewar/corewar", file1, file2], stdout=sp.PIPE, stderr=sp.PIPE)
            stdout, stderr = proc.communicate()
            rc = proc.returncode
            if rc != 0:
                print("Corewar returned with error code: {}".format(rc))
                self.failed += 1
            else:
                buff = stdout.decode("utf-8").split("\n")
                if (len(buff) < 3):
                    self.passed += 1
                    return
                if buff[-2].split("player ")[1].split("(")[0] == buff[-3].split("player ")[1].split("(")[0]:
                    self.passed += 1
                else:
                    print("Corewar: Wrong winner")
                    self.failed += 1

        except FileNotFoundError:
            print("Corewar not found")
            sys.exit(1)



def main():
    args = Parser().parse_args()
    print("Corewar Tester")
    tester = Tester(args["directory"])
    tester.test()


if __name__ == "__main__":
    main()
