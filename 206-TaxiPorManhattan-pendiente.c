#include <stdio.h>
#include <stdint.h>

int32_t find_catetos(int32_t n) {
    int32_t c1 = 1, c2 = 1;
    while (1) {
        c1++;
        while (c2 <= n*n - c1*c1) {
            if (c1*c1 + c2*c2 == n*n) return c1 + c2;
            c2++;
        }
    }
}

int main () {
    int32_t casos, n; 

    scanf("%i", &casos);
    while (casos--) {
        scanf("%i", &n);
        printf("%i\n", find_catetos(n));
    }
    
    return 0;
}
