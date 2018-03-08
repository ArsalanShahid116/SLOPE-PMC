#!/bin/bash

echo "Extracting PMCs from Output Files"

tmp=$(likwid-perfctr -e | grep ', PMC' | awk '{print $1}' | sed 's/.$//' | sed 's/$/ STAT/')

Benchmarks=(output-bt.S)
BNUM=${#Benchmarks[@]}

for (( BCOUNT=0; BCOUNT<${BNUM}; BCOUNT++ ))
do
    EXE=${Benchmarks[$BCOUNT]}

echo "|                Event                | Counter |  |    Count    |    Min   |    Max    |      Avg     |" > PMC_${Benchmarks[$BCOUNT]}

grep "${tmp}" $EXE > PMC_${Benchmarks[$BCOUNT]}

awk '{print $2 " " $7}' PMC_${Benchmarks[$BCOUNT]} > PMCs_${Benchmarks[$BCOUNT]}

rm PMC_${Benchmarks[$BCOUNT]}

done

unset tmp
