#include <stdio.h>
int main() {
    int f, n, pf = 0;
    printf("Enter frames and total pages: ");
    scanf("%d %d", &f, &n);
    int fr[f], pg[n];
    for(int i = 0; i < f; i++) fr[i] = -1;
    printf("Enter pages: ");
    for(int i = 0; i < n; i++) scanf("%d", &pg[i]);

    for (int i = 0; i < n; i++) {
        int found = 0, pos = -1;
        for (int j = 0; j < f; j++) if (fr[j] == pg[i]) found = 1;
        if (!found) {
            for (int j = 0; j < f; j++) if (fr[j] == -1) { pos = j; break; }
            if (pos == -1) {
                int far = i;
                for (int j = 0; j < f; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) if (fr[j] == pg[k]) break;
                    if (k > far) { far = k; pos = j; }
                }
            }
            fr[pos] = pg[i];
            pf++;
        }
    }
    printf("Total Page Faults: %d\n", pf);
    return 0;
}
