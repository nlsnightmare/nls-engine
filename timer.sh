#!/bin/bash
start=$SECONDS
make -j10
duration=$(( SECONDS - start ))
echo $duration

start=$SECONDS
make all
duration=$(( SECONDS - start ))
echo $duration
