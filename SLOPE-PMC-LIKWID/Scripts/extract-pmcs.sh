#!/bin/bash

echo "Seperating PMCs from output file"

BENCHMARKS=() # specify name of output files

BNUM=${#BENCHMARKS[@]}

for (( BCOUNT=0; BCOUNT<${BNUM}; BCOUNT++ ))
do
    EXE=${BENCHMARKS[$BCOUNT]}

echo "|                Event                | Counter |     Sum    |    Min   |    Max    |      Avg     |" > perfcounts_${BENCHMARKS[$BCOUNT]}

grep 'BR_INST_EXEC_ALL_BRANCHES STAT\|BR_MISP_EXEC_ALL_BRANCHES STAT\|BR_INST_RETIRED_ALL_BRANCHES STAT\|BR_MISP_RETIRED_ALL_BRANCHES STAT\|UNCORE_CLOCK STAT\|CBOX_CLOCKTICKS STAT\|SBOX_CLOCKTICKS STAT\|WBOX_CLOCKTICKS STAT\|BBOX_CLOCKTICKS STAT\|DRAM_CLOCKTICKS STAT\|PBOX_CLOCKTICKS STAT\|RBOX_CLOCKTICKS STAT\|QBOX_CLOCKTICKS STAT\|SNOOPS_RSP_AFTER_DATA_LOCAL STAT\|SNOOPS_RSP_AFTER_DATA_REMOTE STAT\|RXL_FLITS_G1_DRS_DATA STAT\|RXL_FLITS_G1_DRS_NONDATA STAT\|OFFCORE_REQUESTS_DEMAND_DATA_RD STAT\|RXL_FLITS_G0_DATA STAT\|RXL_FLITS_G0_NON_DATA STAT\|TXL_FLITS_G0_NON_DATA STAT\|CPU_CLK_UNHALTED_ANY STAT\|CPU_CLOCK_UNHALTED_THREAD_P STAT\|CPU_CLOCK_UNHALTED_THREAD_P_ANY STAT\|CPU_CLOCK_UNHALTED_REF_XCLK STAT\|CPU_CLOCK_UNHALTED_REF_XCLK_ANY STAT\|HA_R2_BL_CREDITS_EMPTY_LO_HA0 STAT\|HA_R2_BL_CREDITS_EMPTY_LO_HA1 STAT\|CPU_CLOCK_THREAD_UNHALTED_ONE_THREAD_ACTIVE STAT\|CPU_CLOCK_UNHALTED_TOTAL_CYCLES STAT\|L2_RQSTS_ALL_DEMAND_DATA_RD_MISS STAT\|L2_RQSTS_ALL_DEMAND_DATA_RD_HIT STAT\|HA_R2_BL_CREDITS_EMPTY_LO_R2_NCB STAT\|HA_R2_BL_CREDITS_EMPTY_LO_R2_NCS STAT\|L2_RQSTS_ALL_DEMAND_DATA_RD STAT\|OFFCORE_REQUESTS_OUTSTANDING_DEMAND_DATA_RD STAT\|OFFCORE_REQUESTS_OUTSTANDING_ALL_DATA_RD STAT\|HA_R2_BL_CREDITS_EMPTY_HI_HA0 STAT\|HA_R2_BL_CREDITS_EMPTY_HI_HA1 STAT\|OFFCORE_REQUESTS_OUTSTANDING_CYCLES_WITH_DATA_RD STAT\|OFFCORE_REQUESTS_OUTSTANDING_DEMAND_DATA_RD_C6 STAT\|UOPS_EXECUTED_PORT_DATA_PORTS STAT\|OFFCORE_REQUESTS_DEMAND_DATA_RD STAT\|HA_R2_BL_CREDITS_EMPTY_HI_R2_NCB STAT\|HA_R2_BL_CREDITS_EMPTY_HI_R2_NCS STAT\|OFFCORE_REQUESTS_ALL_DATA_RD STAT\|L2_TRANS_DEMAND_DATA_RD STAT\|OFFCORE_RESPONSE_0_DMND_DATA_RD_ANY STAT\|CPU_CLOCK_UNHALTED_THREAD_P STAT\|CPU_CLOCK_UNHALTED_THREAD_P_ANY STAT\|CPU_CLOCK_UNHALTED_REF_XCLK STAT\|CPU_CLOCK_UNHALTED_REF_XCLK_ANY STAT\|CPU_CLOCK_THREAD_UNHALTED_ONE_THREAD_ACTIVE STAT\|CPU_CLOCK_UNHALTED_TOTAL_CYCLES STAT\|ICACHE_HIT STAT\|ICACHE_MISSES STAT\|ICACHE_ACCESSES STAT\|ICACHE_IFETCH_STALL STAT\|L2_RQSTS_ALL_DEMAND_DATA_RD_MISS STAT\|L2_RQSTS_ALL_DEMAND_DATA_RD_HIT STAT\|L2_RQSTS_ALL_DEMAND_DATA_RD STAT\|L2_RQSTS_RFO_HIT STAT\|L2_RQSTS_RFO_MISS STAT\|L2_RQSTS_ALL_RFO STAT\|L2_RQSTS_CODE_RD_HIT STAT\|L2_RQSTS_CODE_RD_MISS STAT' $EXE >>  perfcounts_${BENCHMARKS[$BCOUNT]}

grep 'MEM_LOAD_UOPS_RETIRED_ALL_ALL STAT\|UOPS_ISSUED_ANY STAT\|UOPS_ISSUED_FLAGS_MERGE STAT\|UOPS_ISSUED_USED_CYCLES STAT\|UOPS_ISSUED_STALL_CYCLES STAT\|UOPS_ISSUED_TOTAL_CYCLES STAT\|UOPS_ISSUED_CORE_USED_CYCLES STAT\|UOPS_ISSUED_CORE_STALL_CYCLES STAT\|UOPS_ISSUED_CORE_TOTAL_CYCLES STAT\|ARITH_DIVIDER_UOPS STAT\|IDQ_MITE_UOPS STAT\|IDQ_DSB_UOPS STAT\|IDQ_MS_DSB_UOPS STAT\|IDQ_MS_MITE_UOPS STAT\|IDQ_MS_UOPS STAT\|IDQ_ALL_DSB_CYCLES_ANY_UOPS STAT\|IDQ_ALL_DSB_CYCLES_4_UOPS STAT\|IDQ_ALL_MITE_CYCLES_ANY_UOPS STAT\|IDQ_ALL_MITE_CYCLES_4_UOPS STAT\|IDQ_MITE_ALL_UOPS STAT\|IDQ_UOPS_NOT_DELIVERED_CORE STAT\|IDQ_UOPS_NOT_DELIVERED_CYCLES_0_UOPS_DELIV_CORE STAT\|IDQ_UOPS_NOT_DELIVERED_CYCLES_LE_1_UOP_DELIV_CORE STAT\|IDQ_UOPS_NOT_DELIVERED_CYCLES_LE_2_UOP_DELIV_CORE STAT\|IDQ_UOPS_NOT_DELIVERED_CYCLES_LE_3_UOP_DELIV_CORE STAT\|IDQ_UOPS_NOT_DELIVERED_CYCLES_FE_WAS_OK STAT\|UOPS_EXECUTED_PORT_PORT_0 STAT\|UOPS_EXECUTED_PORT_PORT_1 STAT\|UOPS_EXECUTED_PORT_PORT_2 STAT\|UOPS_EXECUTED_PORT_PORT_3 STAT\|UOPS_EXECUTED_PORT_PORT_4 STAT\|UOPS_EXECUTED_PORT_PORT_5 STAT\|UOPS_EXECUTED_PORT_PORT_6 STAT\|UOPS_EXECUTED_PORT_PORT_7 STAT\|UOPS_EXECUTED_PORT_PORT_0_CORE STAT\|UOPS_EXECUTED_PORT_PORT_1_CORE STAT\|UOPS_EXECUTED_PORT_PORT_2_CORE STAT' $EXE >> perfcounts_${BENCHMARKS[$BCOUNT]}

grep 'UOPS_EXECUTED_PORT_PORT_3_CORE STAT\|UOPS_EXECUTED_PORT_PORT_4_CORE STAT\|UOPS_EXECUTED_PORT_PORT_5_CORE STAT\|UOPS_EXECUTED_PORT_PORT_6_CORE STAT\|UOPS_EXECUTED_PORT_PORT_7_CORE STAT\|UOPS_EXECUTED_PORT_ARITH_PORTS STAT\|UOPS_EXECUTED_PORT_ARITH_PORTS_CORE STAT\|UOPS_EXECUTED_PORT_DATA_PORTS STAT\|LSD_UOPS STAT\|LSD_CYCLES_4_UOPS STAT\|UOPS_EXECUTED_THREAD STAT\|UOPS_EXECUTED_USED_CYCLES STAT\|UOPS_EXECUTED_STALL_CYCLES STAT\|UOPS_EXECUTED_TOTAL_CYCLES STAT\|UOPS_EXECUTED_CYCLES_GE_1_UOPS_EXEC STAT\|UOPS_EXECUTED_CYCLES_GE_2_UOPS_EXEC STAT\|UOPS_EXECUTED_CYCLES_GE_3_UOPS_EXEC STAT\|UOPS_EXECUTED_CYCLES_GE_4_UOPS_EXEC STAT\|UOPS_EXECUTED_CORE STAT\|UOPS_EXECUTED_CORE_USED_CYCLES STAT\|UOPS_EXECUTED_CORE_STALL_CYCLES STAT\|UOPS_EXECUTED_CORE_TOTAL_CYCLES STAT\|UOPS_EXECUTED_CORE_CYCLES_GE_1_UOPS_EXEC STAT\|UOPS_EXECUTED_CORE_CYCLES_GE_2_UOPS_EXEC STAT\|UOPS_EXECUTED_CORE_CYCLES_GE_3_UOPS_EXEC STAT\|UOPS_EXECUTED_CORE_CYCLES_GE_4_UOPS_EXEC STAT\|UOPS_RETIRED_ALL STAT\|UOPS_RETIRED_CORE_ALL STAT\|UOPS_RETIRED_RETIRE_SLOTS STAT\|UOPS_RETIRED_CORE_RETIRE_SLOTS STAT\|UOPS_RETIRED_USED_CYCLES STAT\|UOPS_RETIRED_STALL_CYCLES STAT\|UOPS_RETIRED_TOTAL_CYCLES STAT\|UOPS_RETIRED_CORE_USED_CYCLES STAT\|UOPS_RETIRED_CORE_STALL_CYCLES STAT\|UOPS_RETIRED_CORE_TOTAL_CYCLES STAT\|L2_RQSTS_ALL_DEMAND_MISS STAT\|L2_RQSTS_ALL_DEMAND_REFERENCES STAT\|L2_RQSTS_ALL_CODE_RD STAT\|L2_RQSTS_L2_PF_HIT STAT\|L2_RQSTS_L2_PF_MISS STAT' $EXE >> perfcounts_${BENCHMARKS[$BCOUNT]}

done

