#!/bin/env bash

COOKIE=${1:?"Missing argument for session cookie"}
DAYS=${2:-25}

mkdir -p src/input;

for ((i=1; i <= $DAYS; i++));
do
  echo -n "Download input for day $i...";

  curl \
    --cookie "session=$COOKIE" \
    -o ./src/input/day$i \
    --silent \
    "https://adventofcode.com/2015/day/$i/input";

  echo "#ifndef DAY""$i""_INPUT_H" > src/input/day$i.h;
  echo "#define DAY""$i""_INPUT_H" >> src/input/day$i.h;
  echo "" >> src/input/day$i.h;

  xxd -C -i src/input/day$i >> src/input/day$i.h;

  echo "" >> src/input/day$i.h;
  echo "#endif" >> src/input/day$i.h;

  rm src/input/day$i;

  echo " done.";
done
