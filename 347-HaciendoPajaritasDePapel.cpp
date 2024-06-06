#include <iostream>
#include <stdio.h>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;
    while (a != 0 || b != 0) {
        int n; 
        int out = 0;
        while (a >= 10 && b >= 10) {
            int aux;
            if (b > a) {
                aux = b;
                b = a;
                a = aux;
            }
            
            n = a / b;
            aux = b;
            b = a - b*n;
            a = aux;
            out += n;

        }
        std::cout << out << "\n";
        std::cin >> a >> b;

    }
}