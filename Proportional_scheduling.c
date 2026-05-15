#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], burst[n], weight[n];
    int totalWeight = 0;
    float cpuShare[n], allocatedTime[n];

    // Input process details
    for(i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &burst[i]);

        printf("Enter Weight for P%d: ", pid[i]);
        scanf("%d", &weight[i]);

        totalWeight += weight[i];
    }

    // Calculate proportional CPU share
    for(i = 0; i < n; i++) {
        cpuShare[i] = ((float)weight[i] / totalWeight) * 100;
        allocatedTime[i] = ((float)weight[i] / totalWeight) * burst[i];
    }

    // Display results
    printf("\n--- Proportional Scheduling ---\n");
    printf("-------------------------------------------------\n");
    printf("PID\tBurst Time\tWeight\tCPU Share\tAllocated Time\n");
    printf("-------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%.2f%%\t\t%.2f\n",
               pid[i], burst[i], weight[i],
               cpuShare[i], allocatedTime[i]);
    }

    printf("-------------------------------------------------\n");

    return 0;
}
