#include <stdio.h>
#include <iostream>

using namespace std;
int main() {
    int casos;
    scanf("%d\n", &casos);
    int i;
    char nombre[100];
    for (i=0; i < casos; ++i) {
        cin >> nombre >> nombre;
        cout << "Hola, " << nombre << ".\n";
    }
    return 0;
}