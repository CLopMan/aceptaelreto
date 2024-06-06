#include <stdio.h>
#include <iostream>

using namespace std;
int main() {
    int casos;
    scanf("%d\n", &casos);
    int i;
    int pag;
    for (i=0; i < casos; ++i) {
        cin >> pag;
        if (pag%2) {
            printf("%d\n", pag - 1);
        } else {
            printf("%d\n", pag + 1);
        }
    }
    return 0;
}