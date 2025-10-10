#!/usr/bin/env bash
set -euo pipefail
shopt -s nullglob  # if no matches, loop is skipped instead of using literal patterns

# Change this variable to pick the problem
PROBLEM="C"

RUN=./a.out
BASE_DIR="$HOME/Documents/maratona/icpc/2023-2024 ACM-ICPC Latin American Regional Programming Contest/contest-packages"
INPUT_DIR="$BASE_DIR/$PROBLEM/input"
OUTPUT_DIR="$BASE_DIR/$PROBLEM/output"

# optional: ensure expected outputs dir exists
mkdir -p "$OUTPUT_DIR"

tmp_out="$(mktemp)"
any=0

for in_file in "$INPUT_DIR"/"${PROBLEM}"_*; do
  any=1
  idx="$(basename "$in_file")"                   # e.g. C_0001
  expected="$OUTPUT_DIR/$idx"                    # expected output file
  "$RUN" < "$in_file" > "$tmp_out"

  if [[ -f "$expected" ]]; then
    if cmp -s "$tmp_out" "$expected"; then
      echo "OK $idx"
    else
      echo "Mismatch on $idx"
      echo "--> input:"
      cat "$in_file"
      echo "--> expected:"
      cat "$expected"
      echo "--> got:"
      cat "$tmp_out"
      rm -f "$tmp_out"
      exit 1
    fi
  else
    echo "No expected file for $idx at: $expected"
    # Uncomment if you want to save your run as the new expected:
    # cp "$tmp_out" "$expected"
  fi
done

rm -f "$tmp_out"

if [[ $any -eq 0 ]]; then
  echo "No files matched: \"$INPUT_DIR\"/${PROBLEM}_*"
fi
