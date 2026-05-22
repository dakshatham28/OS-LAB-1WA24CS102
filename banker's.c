#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m; // n = number of processes, m = number of resources
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];
    int need[n][m], safeSeq[n];
    bool finish[n];

    // Input allocation matrix
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input maximum matrix
    printf("Enter maximum matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input available resources
    printf("Enter available resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize finish array
    for (int i = 0; i < n; i++) finish[i] = false;

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == m) { // If all needs can be satisfied
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is NOT in a safe state.\n");
            return 0;
        }
    }

    // Print safe sequence
    printf("System is in a SAFE state.\nSafe sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
