#include "main.h"

int counters(
	FILE *fp,
        FILE *fpp,
	char ** eventname,
	int Events[],
	int retval,
	int NUM_EVENTS
)
{
   long long values[NUM_EVENTS];
   
   if ( (retval = PAPI_start_counters(Events, NUM_EVENTS)) != PAPI_OK)
       ERROR_RETURN(retval);

   fprintf(fp, "\nCounter Started: \n");

   naiveMxm(fp, "1000");
   naiveMxv(fp, "20000");
   //system("../benchmarks/bt.A");   

   if ( (retval=PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK)
      ERROR_RETURN(retval);

   fprintf(fp, "Read successfully\n");

   int i=0;
   
   for(i=0;i<NUM_EVENTS;i++)
   fprintf(fpp, "%s:  %lld \n", eventname[i], values[i]);

   if ( (retval = PAPI_stop_counters(values, NUM_EVENTS)) != PAPI_OK)
       ERROR_RETURN(retval);
}

int main(
        int argc,
        char *argv[]
)
{
   int num_hwcntrs = 0;
   int retval;
   
   char errstring[PAPI_MAX_STR_LEN];
   
   FILE *fp, *fpp;
   
   if(argv[1]==NULL)
   {
    printf("Choose set of PAPI events to be profiled [1-14]\n");  
    return(0);
   }

   if(argc != 2)
   {
    printf("invalid number of arguments -- Choose from [1-14]\n");
    return(0);
   }
    
   fp = fopen("Calculations", "a");
   fpp = fopen("PMCs", "a");
   
   if((retval = PAPI_library_init(PAPI_VER_CURRENT)) != PAPI_VER_CURRENT )
   {
      fprintf(stderr, "Error: %d %s\n",retval, errstring);
      exit(1);
   }

   if ((num_hwcntrs = PAPI_num_counters()) < PAPI_OK)
   {
      fprintf(fp, "There are no counters available. \n");
      exit(1);
   }

   fprintf(fp, "There are %d counters in this system\n",num_hwcntrs);

   num_events = atoi(argv[1]);
   
   if(num_events == 1){
   char *eventname[]={
   "PAPI_L1_DCM",
   "PAPI_L1_ICM", 
   "PAPI_L2_DCM", 
   "PAPI_L2_ICM"
   };

   int Events[]={
   PAPI_L1_DCM,
   PAPI_L1_ICM,
   PAPI_L2_DCM,
   PAPI_L2_ICM
   };

    counters(fp, fpp, eventname, Events, retval,4);
   }

   if(num_events == 2){
   char *eventname1[]={
   "PAPI_CA_SHR",
   "PAPI_CA_CLN",
   "PAPI_CA_INV",
   "PAPI_CA_ITV",
   };

   int Events1[]={
   PAPI_CA_SHR,
   PAPI_CA_CLN,
   PAPI_CA_INV,
   PAPI_CA_ITV
   };

    counters(fp, fpp, eventname1, Events1, retval,4);
   }

   if(num_events == 3){
   char *eventname2[]={
   "PAPI_L1_STM",
   "PAPI_L2_LDM",
   "PAPI_L2_STM",
   "PAPI_PRF_DM",
   };

   int Events2[]={
   PAPI_L1_STM,
   PAPI_L2_LDM,
   PAPI_L2_STM,
   PAPI_PRF_DM
   };

    counters(fp, fpp,  eventname2, Events2, retval,4);
   }

   if(num_events == 4){
   char *eventname3[]={
   "PAPI_FUL_CCY",
   "PAPI_BR_UCN",
   "PAPI_BR_CN",
   "PAPI_BR_TKN"
   };

   int Events3[]={
   PAPI_FUL_CCY,
   PAPI_BR_UCN,
   PAPI_BR_CN,
   PAPI_BR_TKN
   };

    counters(fp, fpp, eventname3, Events3, retval,4);
   }

   if(num_events == 5){
   char *eventname4[]={
   "PAPI_BR_NTK",
   "PAPI_BR_MSP",
   "PAPI_BR_PRC",
   "PAPI_TOT_INS"
   };

   int Events4[]={
   PAPI_BR_NTK,
   PAPI_BR_MSP,
   PAPI_BR_PRC,
   PAPI_TOT_INS
   };

    counters(fp, fpp, eventname4, Events4, retval,4);
   }

   if(num_events == 6){
   char *eventname5[]={
   "PAPI_L2_DCR",
   "PAPI_L3_DCR",
   "PAPI_L2_DCW",
   "PAPI_L3_DCW"
   };

   int Events5[]={
   PAPI_L2_DCR,
   PAPI_L3_DCR,
   PAPI_L2_DCW,
   PAPI_L3_DCW
   };

    counters(fp, fpp, eventname5, Events5, retval,4);
   }
 
   if(num_events == 7){
   char *eventname6[]={
   "PAPI_L2_ICH",
   "PAPI_L2_ICA",
   "PAPI_L3_ICA",
   "PAPI_L2_ICR"
   };

   int Events6[]={
   PAPI_L2_ICH,
   PAPI_L2_ICA,
   PAPI_L3_ICA,
   PAPI_L2_ICR
   };

    counters(fp, fpp, eventname6, Events6, retval,4);
   }

   if(num_events == 8){
   char *eventname7[]={
   "PAPI_L3_TCR",
   "PAPI_L2_TCW",
   "PAPI_L3_TCW",
   "PAPI_REF_CYC"
   };

   int Events7[]={
   PAPI_L3_TCR,
   PAPI_L2_TCW,
   PAPI_L3_TCW,
   PAPI_REF_CYC
   };

    counters(fp, fpp, eventname7, Events7, retval,4);
   }

   if(num_events == 9){
   char *eventname8[]={
   "PAPI_L1_TCM",
   "PAPI_L2_TCM",
   "PAPI_L3_TCM"
    };
    
   int Events8[]={
   PAPI_L1_TCM,
   PAPI_L2_TCM,
   PAPI_L3_TCM,   
   };
   
    counters(fp, fpp, eventname8, Events8, retval, 3);
   }

   if(num_events == 10){
   char *eventname9[]={
   "PAPI_L3_LDM",
   "PAPI_L1_LDM",
    };

   int Events9[]={
   PAPI_L3_LDM,
   PAPI_L1_LDM,
   };

    counters(fp, fpp, eventname9, Events9, retval, 2);
   }

   if(num_events == 11){
   char *eventname11[]={
   "PAPI_BR_INS",
   "PAPI_RES_STL"
    };

   int Events11[]={
   PAPI_BR_INS,
   PAPI_RES_STL
   };

    counters(fp, fpp, eventname11, Events11, retval, 2);
   }

   if(num_events == 12){
   char *eventname13[]={
   "PAPI_TOT_CYC",
   "PAPI_L2_DCA",
   "PAPI_L3_DCA"
    };

   int Events13[]={
   PAPI_TOT_CYC,
   PAPI_L2_DCA,
   PAPI_L3_DCA
   };

    counters(fp, fpp, eventname13, Events13, retval, 3);
   }
 
   if(num_events == 13){
   char *eventname14[]={
   "PAPI_L3_ICR",
   "PAPI_L2_TCA",
   "PAPI_L2_TCR"
   };

   int Events14[]={
   PAPI_L3_ICR,
   PAPI_L2_TCA,
   PAPI_L2_TCR
   };

    counters(fp, fpp, eventname14, Events14, retval, 3);
   }  

   if(num_events == 14){
   char *eventname15[]={
   "PAPI_MEM_WCY",
   "PAPI_STL_ICY",
   "PAPI_FUL_ICY",
    };

   int Events15[]={
   PAPI_MEM_WCY,
   PAPI_STL_ICY,
   PAPI_FUL_ICY
   };

    counters(fp, fpp, eventname15, Events15, retval, 3);
   }

   fclose(fp);   
   fclose(fpp);

   PAPI_shutdown();

   exit(0);
}
