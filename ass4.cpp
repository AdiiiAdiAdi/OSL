#include <stdio.h>

int ST[5], AT[5], TAT[5], CT[5], WT[5], BT[5];     //start, arrival, turn around, completion, wait, burst
// tat is the total time taken including wait time in queue               //        <--WT--> <--BT-->
                                                                          //        AT      ST      CT
                                                                          //        <-----TAT------->

void processtime() {
   
    ST[0] = AT[0];   //for first process its start is when it arrived            
    CT[0] = ST[0] + BT[0]; 
    TAT[0] = CT[0] - AT[0];      
    WT[0] = TAT[0] - BT[0];

    
   for (int i = 1; i < 4; i++) {
        ST[i] = CT[i - 1];        // next process starts when previous finishes
        CT[i] = ST[i] + BT[i]; 
        TAT[i] = CT[i] - AT[i]; 
        WT[i] = TAT[i] - BT[i]; 
    }
}

int main() {
    
    for (int i = 0; i < 4; i++) {         // for 4 processes
        printf("What is process %d's arrival time? ", i + 1);
        scanf("%d", &AT[i]);

        printf("What is process %d's burst time? ", i + 1);
        scanf("%d", &BT[i]);
    }

    // Calculate times
    processtime();
    
    int avg_wt = 0;
    int avg_tnt = 0;
    
    for (int p = 0; p < 4; p++) {
        avg_wt += WT[p];
        avg_tnt += TAT[p];
    }
   
    avg_wt = avg_wt / 4;
    avg_tnt = avg_tnt / 4;

    // Print the results
    printf("\nProcess   Arrival Time Burst Time Start Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\t\t %d\t\t  %d\t  %d\t\t  %d\t\t %d\t\t  %d\n",  
               i + 1, AT[i], BT[i], ST[i], CT[i], TAT[i], WT[i]);
    }
    
    printf("\nAverage wait time is: %d", avg_wt);
    printf("\nAverage turn around time is: %d\n", avg_tnt);
    
    return 0;
}
