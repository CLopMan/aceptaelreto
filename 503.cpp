/*https://aceptaelreto.com/problem/statement.php?id=503*/

#include <iostream>
#include <string>

void tratar_caso(int carasA, int carasB) {
    int aux;
    std::string space = "";
    if (carasA > carasB) {
        aux = carasA;
        carasA = carasB;
        carasB = aux;
    }
    int j = 1;
    for (int i = carasA; i <= carasB; ++i) {
        std::cout << space << carasA + j;
        ++j;
        space = " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos; 
    int carasA, carasB;
    std::cin >> casos; 
    for (int i = 0; i < casos; ++i) {
        std::cin >> carasA >> carasB;
        tratar_caso(carasA, carasB);
    }
    return 0; 
}