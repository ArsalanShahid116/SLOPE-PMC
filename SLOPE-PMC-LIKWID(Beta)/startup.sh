#!/bin/bash

echo "Activating MSRs"
sudo modprobe msr
echo "Gernal-Purpose PMCs in pmc.c"
./get-pmcs.sh
echo "Build Executeable"
make
echo "Launch Experiments"
./Execute
echo "Collecting PMCs"
./extract.sh
echo "Save Results"
cp PMCs_output* Results/

