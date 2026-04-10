#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[20];
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct Process proc[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < proc[i].arrival_time) {
            time = proc[i].arrival_time; // CPU idle until process arrives
        }
        proc[i].completion_time = time + proc[i].burst_time;
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
        time += proc[i].burst_time;
    }
}

void printTable(struct Process proc[], int n, char queueName[]) {
    int totalWT = 0, totalTAT = 0;

    printf("\n--- %s Queue (FCFS Scheduling) ---\n", queueName);
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               proc[i].name,
               proc[i].arrival_time,
               proc[i].burst_time,
               proc[i].completion_time,
               proc[i].turnaround_time,
               proc[i].waiting_time);

        totalWT += proc[i].waiting_time;
        totalTAT += proc[i].turnaround_time;
    }

    double avgWT = (double) totalWT / n;
    double avgTAT = (double) totalTAT / n;

    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
}

int main() {
    int sys_n, user_n;

    printf("Enter number of system processes: ");
    scanf("%d", &sys_n);
    struct Process sys_proc[sys_n];

    for (int i = 0; i < sys_n; i++) {
        printf("Enter name, arrival time, burst time for System Process %d: ", i + 1);
        scanf("%s %d %d", sys_proc[i].name, &sys_proc[i].arrival_time, &sys_proc[i].burst_time);
    }

    printf("Enter number of user processes: ");
    scanf("%d", &user_n);
    struct Process user_proc[user_n];

    for (int i = 0; i < user_n; i++) {
        printf("Enter name, arrival time, burst time for User Process %d: ", i + 1);
        scanf("%s %d %d", user_proc[i].name, &user_proc[i].arrival_time, &user_proc[i].burst_time);
    }

    // Schedule system processes first (higher priority)
    fcfs(sys_proc, sys_n);
    printTable(sys_proc, sys_n, "System");

    // Then schedule user processes
    fcfs(user_proc, user_n);
    printTable(user_proc, user_n, "User");

    printf("\nNote: System processes are executed before user processes.\n");

    return 0;
}

