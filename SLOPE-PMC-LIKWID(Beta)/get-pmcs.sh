#!/bin/bash

likwid-perfctr -e | grep ', PMC' | awk '{print $1}' | sed 's/.$//' | sed -e 's/^/"/' | sed 's/$/",/' | sed '1s/^/char * b[] = { /' | sed  -e "\$a };" > pmcs.c

