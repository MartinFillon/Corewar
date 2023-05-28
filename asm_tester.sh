#!/bin/bash

MYASM="asm/asm"

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

SRC_DIR="./champions/"
EXPECTED_DIR="./champions/expected/"
OUTPUT_DIR="./champions/"

if [ ! -f $MYASM ]; then
    echo "asm not found"
    exit 1
fi

if [ ! -f $1 ]; then
    echo "file not found"
    exit 1
fi

for ele in "$SRC_DIR"*.s; do
    filename=$(basename "$ele" .s)
    $MYASM $ele
    diff_result=$(diff "$OUTPUT_DIR"$filename.cor "$EXPECTED_DIR"$filename.cor)

    if [ "$diff_result" ]; then
        echo -e "${RED}KO${NC} - Differences found for $filename"
        echo "$diff_result"
        hexdump_diff=$(diff <(hexdump -C "$OUTPUT_DIR$filename.cor") <(hexdump -C "$EXPECTED_DIR$filename.cor"))
        echo "$hexdump_diff" > "$OUTPUT_DIR$filename.report"
    else
        echo -e "${GREEN}OK${NC} - No differences found for $filename"
    fi
done
