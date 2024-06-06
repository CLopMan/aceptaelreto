#include <stdio.h>

int main() {
    int casos;
    scanf("%d\n", &casos);
    int i;
    for (i=0; i < casos; ++i) {
        int horas;
        int encendidos;
        int hpe;
        scanf("%d %d %d", &horas, &encendidos, &hpe);
        int comparador = encendidos*hpe;
        if (comparador < horas) {
            printf("ENCENDIDOS\n");
        } else if (comparador > horas) {
            printf("HORAS\n");
        } else {
            printf("AMBAS\n");
        }
    }
    return 0;
}