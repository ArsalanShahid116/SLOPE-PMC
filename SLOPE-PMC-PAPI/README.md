# SLOPE-PMC-PAPI: Automated PMCs Collection on Intel based multicore servers using PAPI
----------------------------------

Copyright 2017 Arsalan Shahid & Ravi Manumachu <br />
(arsalan.shahid @ ucdconnect.ie, ravi.manumachu @ ucd.ie) <br />

SLOPE-PMC-PAPI is an automated tool for collecting Performance Monitoring Counters <br />
(PMCs) on Intel based multicore systems using PAPI. <br />

### Required Software 
----------------------
1. C+ compiler <br />
2. cmake <br />
3. PAPI (Latest version) <br />
4. numactl <br />

### How to use SLOPE-PMC-PAPI?
------------------------------
1. Add benchmarks in 'benchmarks' directory in SLOPE-PMC-PAPI <br />
2. Go to SLOPE-PMC/SLOPE-PMC-PAPI/src <br />
3. Specify function to be profiled in 'main.c' <br />
4. Run 'execute.sh' <br />
5. Collect results from SLOPE-PMC-PAPI/bin <br />
6. Example results are given in SLOPE-PMC-PAPI/example-results <br />