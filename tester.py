#!/usr/bin/env python3

import argparse
import os
import subprocess as sp
import sys


class Parser:
    def __init__(self):
        self.parser = argparse.ArgumentParser(prog="Corewar Tester")
        self.parser.add_argument(
            "-d",
            "--directory",
            type=str,
            help='Path to the directory containing the ".cor" files',
            required=True,
        )
        self.parser.add_argument(
            "-ci",
            "--exec_in_ci",
            action=argparse.BooleanOptionalAction,
            help="If the script is executed in a CI environment",
            default=False,
        )

    def parse_args(self) -> dict:
        return {k: v for k, v in self.parser.parse_args()._get_kwargs()}


class Tester:
    directory: str
    files: list[str]
    failed: int
    passed: int
    is_ci: bool

    def __init__(self, directory: str, is_ci: bool = False):
        self.is_ci = is_ci
        self.directory = directory
        self.files = [file for file in os.listdir(directory) if file.endswith(".cor")]
        self.files = [os.path.join(directory, file) for file in self.files]
        self.failed = 0
        self.passed = 0

    def test(self) -> None:
        print(f"\nTesting: 2 files\n")

        for file in self.files:
            for file2 in self.files:
                print(f"Testing: {file} & {file2}")
                self.run_test(file, file2)

        print(f"\nTesting: 3 files\n")

        for file in self.files:
            for file2 in self.files:
                for file3 in self.files:
                    print(f"Testing: {file} & {file2} & {file3}")
                    self.run_test(file, file2, file3)

        if not self.is_ci:
            print(f"\nTesting: 4 files\n")

            for file in self.files:
                for file2 in self.files:
                    for file3 in self.files:
                        for file4 in self.files:
                            print(f"Testing: {file} & {file2} & {file3} & {file4}")
                            self.run_test(file, file2, file3, file4)

        print(f"Passed: {self.passed}")
        print(f"Failed: {self.failed}")

    def run_test(self, *files) -> None:
        try:
            proc = sp.Popen(
                ["./corewar/corewar", *files], stdout=sp.PIPE, stderr=sp.PIPE
            )

            stdout, stderr = proc.communicate()
            rc = proc.returncode
            err = stderr.decode("utf-8")

            if rc != 0 or err != "":
                print(
                    f"::error title={'-'.join(files)}::Corewar returned with error: {repr(err)}"
                )
                print(f"Corewar returned with error code: {rc}")
                self.failed += 1
            else:
                buff = stdout.decode("utf-8").split("\n")
                if len(buff) < 3:
                    self.passed += 1
                    return
                if (
                    buff[-2].split("player ")[1].split("(")[0]
                    == buff[-3].split("player ")[1].split("(")[0]
                ):
                    self.passed += 1
                else:
                    print(f"::error title={'-'.join(files)}::Corewar wrong winner")
                    self.failed += 1

        except FileNotFoundError:
            print("Corewar not found")
            sys.exit(1)


def main():
    args = Parser().parse_args()
    print("Corewar Tester")
    tester = Tester(args["directory"], args["exec_in_ci"])
    tester.test()


if __name__ == "__main__":
    main()
