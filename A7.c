#include <stdio.h>

int main() {
    int n;//no of processes
    int m;//no of resouce types
    int i;
    int j;
    int k;

    // Get number of processes and resource types
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m];
    int f[n];//boolean - type array used to track if a process is completed
    int ans[n];//This array stores the safe sequence of process execution
    int ind = 0;//ind is the index tracker

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources (size %d):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array
    for (i = 0; i < n; i++) {
        f[i] = 0;
    }

    // Safety Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int safe = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("\nSystem is in a SAFE state.\n");
        printf("Safe Sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d", ans[i]);
            if (i != n - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
        return 0;
    }

    // Resource Request
    int p; // Process making the request
    printf("\nEnter the process number (P0 to P%d) making a resource request: ", n - 1);
    scanf("%d", &p);

    int req[m];
    printf("Enter request vector for P%d:\n", p);
    for (i = 0; i < m; i++) {
        scanf("%d", &req[i]);
    }

    // Check if request <= need
    for (i = 0; i < m; i++) {
        if (req[i] > need[p][i]) {
            printf("\nError: Request exceeds the process's maximum need.\n");
            return 0;
        }
    }

    // Check if request <= available
    for (i = 0; i < m; i++) {
        if (req[i] > avail[i]) {
            printf("\nResources not available. Process must wait.\n");
            return 0;
        }
    }

    // Tentatively allocate requested resources
    for (i = 0; i < m; i++) {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }

    // Check new safety
    for (i = 0; i < n; i++) f[i] = 0;
    ind = 0;
    int temp_avail[m];
    for (i = 0; i < m; i++) temp_avail[i] = avail[i];

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > temp_avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    for (j = 0; j < m; j++) {
                        temp_avail[j] += alloc[i][j];
                    }
                    f[i] = 1;
                    ans[ind++] = i;
                }
            }
        }
    }

    safe = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("\nRequest can be granted. System remains in a SAFE state.\n");
        printf("New Safe Sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d", ans[i]);
            if (i != n - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nRequest CANNOT be granted. It leads to an unsafe state.\n");
        // Rollback
        for (i = 0; i < m; i++) {
            avail[i] += req[i];
            alloc[p][i] -= req[i];
            need[p][i] += req[i];
        }
    }

    return 0;
}

