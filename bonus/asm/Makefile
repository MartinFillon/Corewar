##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile for asm
##

.DEFAULT_GOAL := run

setup: requirements.txt
	pip3 install -r requirements.txt

run: setup
	python3 interface_input.py

clean:
	rm -rf __pycache__

.PHONY: run clean
