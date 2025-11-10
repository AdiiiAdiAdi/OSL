#include <stdio.h>

int ST[5], AT[5], TAT[5], CT[5], WT[5], BT[5];     #start, arrival, turn around, completion, wait, burst


void processtime(int ST[], int BT[]) {
   
    ST[0] = AT[0]; 
    CT[0] = ST[0] + BT[0]; 
    TAT[0] = CT[0] - AT[0];      # tat is the total time taken including wait time in queue
    WT[0] = TAT[0] - BT[0];


    for (int i = 1; i < 5; i++) {
        ST[i] = CT[i - 1]; 
        CT[i] = ST[i] + BT[i]; 
        TAT[i] = CT[i] - AT[i]; 
        WT[i] = TAT[i] - BT[i]; 
    }
}

int main() {
    
    for (int i = 1; i < 5; i++) {
        printf("What is process %d's arrival time? ", i );
        scanf("%d", &AT[i]);

        printf("What is process %d's burst time? ", i );
        scanf("%d", &BT[i]);
    }

    // Calculate times
    processtime(ST, BT);
    
    int avg_wt;
    int avg_tnt;
    
    for (int p=0; p<4; p++){
   avg_wt += WT[p];
   avg_tnt += TAT[p];
   }
   
   avg_wt= avg_wt/4;
   avg_tnt = avg_tnt/4;

    // Print the results
  printf("Process   Arrival Time Burst Time Start Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 1; i < 5; i++) {
        printf("%d\t\t %d\t\t  %d\t  %d\t\t  %d\t\t %d\t\t  %d\n",  i , AT[i], BT[i], ST[i], CT[i], TAT[i], WT[i]);
    }
    
    printf("average wait time is: %d", avg_wt);
    printf("average turn around time is: %d", avg_tnt);
    
    int allprocess[7];
    


    return 0;
}

    
