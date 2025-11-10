#include <stdio.h>
#include <climits>

int ST[7], AT[7], TAT[7], CT[7], WT[7], BT[7], RT[7];  //  processes 1-6

void processtime(int AT[], int BT[]) {
    int complete = 0,  i;
    for (i = 1; i < 7; i++) {
        RT[i] = BT[i];
    }
int s;   //index of the shortest process
int min;
int time = 0;
    while (complete < 6) {
        s = 0;
        min = INT_MAX;

        for (i = 1; i < 7; i++) {
            if (AT[i] <= time && RT[i] > 0 && RT[i] < min) {      //if the process has arrived && process has some RT  &&  RT is the minimum 
                min = RT[i];
                s = i;
            }
        }
       			 if (RT[s] == BT[s]) {
           			 ST[s] = time;     //record start time 
       						 }

       		 RT[s]--;   //decrement its rt since it executed
       		 time++;

      if (RT[s] == 0) {   //calculate rest, process has finished
          CT[s] = time;
          TAT[s] = CT[s] - AT[s];
          WT[s] = TAT[s] - BT[s];
          complete++;
        }
    }
}

int main() {
    for (int i = 1; i < 7; i++) {
        printf("What is process %d's arrival time? ", i);
        scanf("%d", &AT[i]);
        printf("What is process %d's burst time? ", i);
        scanf("%d", &BT[i]);
    }

    processtime(AT, BT);

    int avg_wt = 0, avg_tat = 0;
    for (int i = 1; i <= 6; i++) {
        avg_wt += WT[i];
        avg_tat += TAT[i];
    }

    avg_wt = avg_wt / 6;
    avg_tat = avg_tat / 6;

    printf("Process   AT  BT  ST  CT  TAT  WT\n");
    for (int i = 1; i <= 6; i++) {
        printf("%d\t   %d   %d   %d   %d   %d   %d\n", i, AT[i], BT[i], ST[i], CT[i], TAT[i], WT[i]);
    }

    printf("Average Waiting Time: %d\n", avg_wt);
    printf("Average Turnaround Time: %d\n", avg_tat);

    return 0;
}

