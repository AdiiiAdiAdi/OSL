#include <stdio.h>
#include <climits>

int ST[5], AT[5], TAT[5], CT[5], WT[5], BT[5], RT[5];

void processtime(int AT[], int BT[]) {
    int complete = 0,  i;
    for (i = 1; i < 7; i++) {
        RT[i] = BT[i];
    }
int s;
int min;
int time = 0;
    while (complete < 6) {
        s = 0;
        min = INT_MAX;

        for (i = 1; i < 7; i++) {
            if (AT[i] <= time && RT[i] > 0 && RT[i] < min) {
                min = RT[i];
                s = i;
            }
        }


	
       			 if (RT[s] == BT[s]) {
           			 ST[s] = time;
       						 }

       		 RT[s]--;
       		 time++;

      if (RT[s] == 0) {
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

    avg_wt = avg_wt / 4;
    avg_tat = avg_tat / 4;

    printf("Process   AT  BT  ST  CT  TAT  WT\n");
    for (int i = 1; i <= 6; i++) {
        printf("%d\t   %d   %d   %d   %d   %d   %d\n", i, AT[i], BT[i], ST[i], CT[i], TAT[i], WT[i]);
    }

    printf("Average Waiting Time: %d\n", avg_wt);
    printf("Average Turnaround Time: %d\n", avg_tat);

    return 0;
}

