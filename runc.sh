#!/usr/bin/env sh

gcc $1 $2 $3 -o temp.out
./temp.out
rm -rf ./temp.out
