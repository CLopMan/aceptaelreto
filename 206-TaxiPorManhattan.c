#include <stdio.h>
#include <stdint.h>
#include <math.h>


uint16_t find_catetos(uint16_t n) {
    uint16_t c1 = 1;
    float c2;
    for (c1 = 1; c1 < 30000; ++c1) {
       c2 = sqrtf((float)(n*n - c1*c1));
//       printf(">> %f   %hu %hu\n", c2, c1, (uint16_t)c2); 
       if ((int)c2 == c2) return c1 + (uint16_t)c2;
    }
    return 0;
}

int main () {
    uint16_t casos, n; 

    scanf("%hu", &casos);
    while (casos--) {
        scanf("%hu", &n);
        printf("%hu\n", find_catetos(n));
    }
    
    return 0;
}
