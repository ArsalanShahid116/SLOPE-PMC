#!/bin/bash

echo "Building SLOPE-PMC-PAPI"
make

echo "Build successfull"

echo "Running Exe"

## This script can be used to collect all the PMCs from SLOPE-PMC-PAPI ##
## Binding the function to cpu cores and running application ##
## Make sure to have 'numactl' utility installed in your OS ##

numactl --physcpubind=0-47 ./main "1" >> Calculations
numactl --physcpubind=0-47 ./main "2" >> Calculations
numactl --physcpubind=0-47 ./main "3" >> Calculations
numactl --physcpubind=0-47 ./main "4" >> Calculations
numactl --physcpubind=0-47 ./main "5" >> Calculations
numactl --physcpubind=0-47 ./main "6" >> Calculations
numactl --physcpubind=0-47 ./main "7" >> Calculations
numactl --physcpubind=0-47 ./main "8" >> Calculations
numactl --physcpubind=0-47 ./main "9" >> Calculations
numactl --physcpubind=0-47 ./main "10" >> Calculations
numactl --physcpubind=0-47 ./main "11" >> Calculations
numactl --physcpubind=0-47 ./main "12" >> Calculations
numactl --physcpubind=0-47 ./main "13" >> Calculations

echo "Execution Finished -- Saving outputs to results directory"

## Saving results to bin directory ##

cp PMCs ../bin/PMCs
cp Calculations ../bin/Calculations

echo "Clean outputs"

## Clean up ##

make clean
rm PMCs Calculations

