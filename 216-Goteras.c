#include <stdio.h>

void printTime(int n) {
    int horas, minutos, segundos;
    horas = n / 3600;
    minutos = (n - horas*3600) / 60;
    segundos = n - horas*3600 - minutos*60;

    printf("%02d:%02d:%02d\n", horas, minutos, segundos);
}


int main () {
    int casos, n, i;
    scanf("%d", &casos);
    for (i = 0; i < casos; ++i) {
        scanf("%d", &n);
        printTime(n);
    }
    return 0;
}
