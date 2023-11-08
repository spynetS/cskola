#!/usr/bin/env sh

if [[ $1 == "eof" ]];
then
    cp templateEOF.c ./lec$2/$3
else
    cp template.c ./lec$1/$2
fi
