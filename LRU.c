#include <stdio.h>
int main() {
    int f, n, pf = 0;
    printf("Enter frames and total pages: ");
    scanf("%d %d", &f, &n);
    int fr[f], tm[f], pg[n];
    for(int i = 0; i < f; i++) fr[i] = -1;
    printf("Enter pages: ");
    for(int i = 0; i < n; i++) scanf("%d", &pg[i]);

    for (int i = 0; i < n; i++) {
        int found = 0, pos = -1;
        for (int j = 0; j < f; j++) if (fr[j] == pg[i]) { found = 1; pos = j; }
        if (found) {
            tm[pos] = i;
        } else {
            for (int j = 0; j < f; j++) if (fr[j] == -1) { pos = j; break; }
            if (pos == -1) {
                int min = tm[0]; pos = 0;
                for (int j = 1; j < f; j++) if (tm[j] < min) { min = tm[j]; pos = j; }
            }
            fr[pos] = pg[i];
            tm[pos] = i;
            pf++;
        }
    }
    printf("Total Page Faults: %d\n", pf);
    return 0;
}
