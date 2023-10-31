#!/usr/bin/env sh

if [[ $1 == "eof" ]];
then
    cp templateEOF.c $2
else
    cp template.c $1
fi
