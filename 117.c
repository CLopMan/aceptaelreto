#include <stdio.h>

int main() {
    int casos;
    scanf("%d\n", &casos);
    int i;
    char nombre[100];
    for (i=0; i < casos; ++i) {
        fgets(nombre, 100, stdin);
        printf("Hola, %s", &nombre[4]);
    }
    return 0;
}