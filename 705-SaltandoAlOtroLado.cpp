/*https://aceptaelreto.com/problem/statement.php?id=705*/

#include <iostream> 

int main() {
    int casos; 
    int piedras; 
    int piedraA = 0, piedraB = 0;
    int p, r;
    int longitud_salto;
    std::cin >> casos;

    for (int i = 0; i < casos; ++i) {
        piedraA = 0; 
        piedraB = 0; 
        p = 0;
        r = 0;
        std::cin >> piedras; 
        for (int j = 0; j < piedras; ++j) {
            std::cin >> piedraB;
            longitud_salto = piedraB - piedraA;
            if (longitud_salto == r) {
                --r;
            } else if (longitud_salto > r) {
                if (longitud_salto > p) {
                    r = longitud_salto - 1;
                    p = longitud_salto;
                } else {
                    p++;
                    r = p;
                }
            }
            
            
            piedraA = piedraB;
        }
        std::cout << p << "\n";
    }
    return 0; 
}