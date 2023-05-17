#! /usr/bin/env python3

import sys
import os
import subprocess as sp
import argparse

ASM_REF = "./bonus/asm"
ASM = "./asm/asm"

class Parser:
    def __init__(self):
        self.parser = argparse.ArgumentParser(prog="Minishell2_tester")
        self.parser.add_argument(
            "-d", "--directory", help="Directory", required=True)
        self.parser.add_argument(
            "-v",
            "--verbose",
            help="Verbose mode",
            action=argparse.BooleanOptionalAction,
            default=False,
        )
        self.parser.add_argument(
            "-ci",
            "--github-ci",
            help="Github CI mode",
            action=argparse.BooleanOptionalAction,
            default=False,
        )

    def parse_args(self) -> dict:
        return {k: v for k, v in self.parser.parse_args()._get_kwargs()}

class Test:
    files: list
    failed: bool
    verbose: bool
    github_ci: bool
    def __init__(self, args: dict) -> None:
        self.files = []
        self.failed = False
        self.verbose = args["verbose"]
        self.github_ci = args["github_ci"]
        self.get_files(args["directory"])

    def get_files(self, directory: str) -> None:
        for file in os.listdir(directory):
            self.files.append(file)
    
    def _printAnnotation(self, message: str, test_name: str = "", file=sys.stdout):
        if self.ci_mode:
            print(
                f"::error title={test_name}:: Test failed", end="", file=file)
        print(message, file=file)

    def run_binary(self, binary: str, file: str):
        try:
            proc = sp.Popen([binary, file], stdin=sp.PIPE,
                            stdout=sp.PIPE, stderr=sp.PIPE)
        
            if self.verbose:
                print(f"Running {binary} on {file}")
            
            proc.communicate()

            return (proc.returncode)

        except FileNotFoundError:
            self._printAnnotation(
                f"[{binary}] not found", test_name=file, file=sys.stderr
            )
            sys.exit(1)

    def read_file(self, file: str) -> list[bytes]:
        tmp, file_cor = os.path.split(file)
        file_cor = file_cor.replace(".s", ".cor")
        print(file_cor)
        try:
            with open(file_cor, "rb") as f:
                return f.readlines()
        except FileNotFoundError:
            self._printAnnotation(
                f"[{file}] not found", test_name=file, file=sys.stderr
            )
            sys.exit(1)

    def run_tests(self) -> None:
        for file in self.files:
            if (file.endswith(".s") == False):
                continue
            print(f"Running test {file}")
            returncode = self.run_binary(ASM, file)
            print(returncode)
            if (returncode == 0):
                file_cor = self.read_file(file)
            returncode_ref = self.run_binary(ASM_REF, file)
            if (returncode_ref == 0):
                file_cor_ref = self.read_file(file)
            if (returncode == 0 and returncode_ref == 0):
                if (file_cor == file_cor_ref):
                    if self.verbose:
                        print(f"Test {file} passed")
                else:
                    self._printAnnotation(
                        f"Test {file} failed", test_name=file, file=sys.stderr
                    )
                    self.failed = True
            
            elif (returncode != 0 and returncode_ref != 0):
                if (returncode != returncode_ref):
                    self._printAnnotation(
                        f"Test {file} failed", test_name=file, file=sys.stderr
                    )
                    self.failed = True
                else:
                    if self.verbose:
                        print(f"Test {file} passed")


if __name__ == "__main__":
    parser = Parser()
    args = parser.parse_args()
    test = Test(args)
    test.run_tests()
    if test.failed:
        sys.exit(1)
    else:
        sys.exit(0)
