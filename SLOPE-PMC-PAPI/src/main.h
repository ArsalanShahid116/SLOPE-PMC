#include "stdio.h"
#include "stdlib.h"
#include "papi.h"
#include "../benchmarks/naive-mm-mv.c"

#ifndef SLOPE_PMC_PAPI_
#define SLOPE_PMC_PAPI_

static int num_events;

#define ERROR_RETURN(retval) { fprintf(stderr, "Error %d %s:line %d: \n", retval,__FILE__,__LINE__);  exit(retval); }

int counters(
        FILE *fp,
        FILE *fpp,
        char ** eventname,
        int Events[],
        int retval,
        int NUM_EVENTS
);

int main(
        int argc,
        char *argv[]
);

   int num_hwcntrs;
   int retval;
   int i;

   char errstring[PAPI_MAX_STR_LEN];

   FILE *fp, *fpp;


#endif

