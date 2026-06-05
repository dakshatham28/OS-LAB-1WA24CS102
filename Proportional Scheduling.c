#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, tot = 0;
    srand(time(NULL));
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int tk[n], bt[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst and tickets for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &tk[i]);
    }

    while (1) {
        int act_tk = 0, sum = 0;
        for (int i = 0; i < n; i++) if (bt[i] > 0) act_tk += tk[i];
        if (act_tk == 0) break;

        int win = rand() % act_tk;
        for (int i = 0; i < n; i++) {
            if (bt[i] > 0) {
                sum += tk[i];
                if (win < sum) {
                    bt[i]--;
                    printf("P%d runs. Remaining: %d\n", i + 1, bt[i]);
                    break;
                }
            }
        }
    }
    return 0;
}
