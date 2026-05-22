#include <stdio.h>

int main() {
    int b[10], p[10], alloc[10], bs, ps, i, j, ch, idx;

    printf("Enter number of blocks: ");
    scanf("%d", &bs);
    printf("Enter block sizes:\n");
    for(i = 0; i < bs; i++) scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &ps);
    printf("Enter process sizes:\n");
    for(i = 0; i < ps; i++) { scanf("%d", &p[i]); alloc[i] = -1; }

    printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit\nChoice: ");
    scanf("%d", &ch);

    for(i = 0; i < ps; i++) {
        idx = -1;
        for(j = 0; j < bs; j++) if(b[j] >= p[i]) {
            if(ch == 1) { idx = j; break; }
            if(ch == 2 && (idx == -1 || b[j] < b[idx])) idx = j;
            if(ch == 3 && (idx == -1 || b[j] > b[idx])) idx = j;
        }
        if(idx != -1) { alloc[i] = idx; b[idx] -= p[i]; }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i = 0; i < ps; i++)
        printf("P%d\t%d\t%s\n", i+1, p[i], alloc[i] != -1 ?
               (char[10]){alloc[i]+49,0} : "Not Allocated");
    return 0;
}
