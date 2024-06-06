/*#include <stdio.h>
int main() {
    int long long n;
    int long long procesing;
    FILE* sample = fopen("sample.in", "r");
    while (fscanf(sample,"%lld", &n) != EOF) {
    int long long it = 1;
    int long long out = 0;
    while (n > 0) {
        procesing = n % 10;
        out = out + it*procesing;
        n = n / 10;
        it = 100*it;
    }
    printf("%lld\n", out);
    }
    return 0;
}
*/

#include <stdio.h>

int main() {
    char d;
    int it = 1;
    while (scanf("%c", &d) != EOF) {
        if (d == '\n') {
            printf("\n");
            it = 1;
        } else {
            if (it) {
                printf("%c", d);
            } else {
                printf("0%c", d);
            }
            it = 0;
        }
    }
    return 0;
}