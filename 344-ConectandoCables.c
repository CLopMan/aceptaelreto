#include<stdio.h>

int main() {
    int casos, countH = 0, countM = 0, cables;
    scanf("%d", &casos);
    while (casos--) {
        char c = 'i';
        countH = 0;
        countM = 0;
        scanf("%d", &cables); 
        while (countH + countM < cables*2) {
            c = getchar();
            if (c == 'M') countM++;
            else if(c == 'H')  countH++;
        }
        if (countH == countM) printf("POSIBLE\n");
        else printf("IMPOSIBLE\n");
    }

    return 0;
}
