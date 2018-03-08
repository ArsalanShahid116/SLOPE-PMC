/***************************************************************************
Copyright 2018 - Arsalan Shahid (arsalan.shahid@ucdconnect.ie)
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at
your option) any later version. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the GNU General Public License for more details. You
should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"pmcs.c"

int main(int argc, char *argv[])
{
    char* APPS[]= {"bt.S"}; // Specify your applications here
    char String[1000];

    int i=0,j=0;
    double SizeOfPmcs=0.00;
    int SizeOfPmc=0,SizeOfApps=0;

    double integer=0.00,ext=0.00;
    int extra=0, loopIter=0;
   
    SizeOfPmcs = (sizeof(b)/sizeof(b[0]));
    SizeOfApps = (sizeof(APPS)/sizeof(APPS[0]));
   
    printf("Available Gernal-Purpose PMCs \n");

    for(i=0;i<SizeOfPmcs;i++){
        printf("(%d) %s | ", i+1, b[i]);
        }

    printf("\n");

    for(j=0;j<SizeOfApps;j++){

    printf(" \n Executing %s to collect PMCs \n",APPS[j]);

    if(SizeOfPmcs/4 == 0){
        for(i=0;i<SizeOfPmcs;i=i+4){
            sprintf(String, "/bin/bash -c 'likwid-perfctr -f -C S0:0-11 -g %s:PMC0,%s:PMC1,%s:PMC2,%s:PMC3 ./%s' >> output-%s",b[i],b[i+1],b[i+2],b[i+3],APPS[j],APPS[j]);
            system(String);
            }
        } 
    else {
	ext = modf(SizeOfPmcs/4, &integer);
        extra = ext * 4;
        loopIter = SizeOfPmcs - extra;   
	for(i=0;i<loopIter;i=i+4){
        	sprintf(String, "/bin/bash -c 'likwid-perfctr -f -C S0:0-11 -g %s:PMC0,%s:PMC1,%s:PMC2,%s:PMC3 ./%s' >> output-%s",b[i],b[i+1],b[i+2],b[i+3],APPS[j],APPS[j]);
        	system(String);
            }
        
	SizeOfPmc = SizeOfPmcs;

        if(extra == 3){
	sprintf(String, "/bin/bash -c 'likwid-perfctr -f -C S0:0-11 -g %s:PMC0,%s:PMC1,%s:PMC2 ./%s' >> output-%s",b[SizeOfPmc-3],b[SizeOfPmc-2],b[SizeOfPmc-1],APPS[j],APPS[j]);
        system(String);
	}
	else if(extra == 2){
        sprintf(String, "/bin/bash -c 'likwid-perfctr -f -C S0:0-11 -g %s:PMC0,%s:PMC1 ./%s' >> output-%s",b[SizeOfPmc-2],b[SizeOfPmc-1],APPS[j],APPS[j]);
        system(String);
	}
	else if(extra == 1){
        sprintf(String, "/bin/bash -c 'likwid-perfctr -f -C S0:0-23 -g %s:PMC0 ./%s' >> output-%s",b[SizeOfPmc-1],APPS[j],APPS[j]);
        system(String);
	}
      }
    }
    printf("PMC Collection Complete");

    return 0;
}