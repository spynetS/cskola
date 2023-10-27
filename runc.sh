#!/usr/bin/env sh

gcc $1 -o temp.out
./temp.out
rm -rf ./temp.out
