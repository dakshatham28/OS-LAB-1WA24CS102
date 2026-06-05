#include <stdio.h>
int main() {
    int f, n, pf = 0, idx = 0;
    printf("Enter frames and total pages: ");
    scanf("%d %d", &f, &n);
    int fr[f], pg[n];
    for(int i = 0; i < f; i++) fr[i] = -1;
    printf("Enter pages: ");
    for(int i = 0; i < n; i++) scanf("%d", &pg[i]);

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) if (fr[j] == pg[i]) found = 1;
        if (!found) {
            fr[idx] = pg[i];
            idx = (idx + 1) % f;
            pf++;
        }
    }
    printf("Total Page Faults: %d\n", pf);
    return 0;
}
