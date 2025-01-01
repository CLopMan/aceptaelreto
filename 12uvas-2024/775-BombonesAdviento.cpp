#include <iostream>

/* Necesitas n + m elementos para tener dos conjuntos disjuntos de n y m
 * elementos respectivamente*/

int main() {
    while (true) {
        int64_t curr, prev, out=0; 
        std::cin >> curr;
        if (curr == 0) return 0;
        
        prev = curr;
        out = curr;
        while (curr != 0) {
            std::cin >> curr;
            int64_t candidate = curr + prev;
            if (candidate > out) out = candidate;
            prev = curr;
        }

        std::cout << out << "\n";
         
    } 
    return 0;
}
