/*#include <stdio.h>

int main() {
    FILE* sample = fopen("sample.in", "r");

    int long p, d, n;
    int long out = 0;

    // input
    do {
        fscanf(sample, "%ld", &p);
        int long i;
        for (i = 0; i < p; i = i + 1) {
            fscanf(sample ,"%ld %ld", &d, &n);
            // out calculation
            if (out < d) {
                out = d;
            } else {
                int long aux = out - d;
                out = out + (n - aux % n);
            }        
        }
        if (out != 0){ 
            printf("%ld\n", out);
        }
        out = 0;

    }
    while (p != 0);
}*/


#include <stdio.h>

int main() {
    int p, d, n;
    int out = 0;

    // input
    do {
        scanf("%d", &p);
        int i;
        for (i = 0; i < p; ++i) {
            scanf("%d %d", &d, &n);
            // out calculation
            if (out < d) {
                out = d;
            } else {
                int aux = out - d;
                out = out + (n - aux % n);
            }        
        }
        if (out != 0){
            printf("%d\n", out);
        }
        out = 0;

    }
    while (p != 0);
    return 0;
}