#include <stdio.h>

int darkSideTendency(long int m) {
    long int counter = 0;
    while(m != 0) {
        int remainder = m % 5;
        m = m / 5;
        if (4 == remainder) counter++;
        if (counter > 1) return 1;
    }
    return 0;
}


int main() {
    long int casos, miniclorianos;
    scanf("%li", &casos);
    while (casos--) {
        scanf("%li", &miniclorianos);
        if (darkSideTendency(miniclorianos)) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
