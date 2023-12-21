/*https://aceptaelreto.com/problem/statement.php?id=397&potw=1*/

#include <iostream>
#include <stdint.h>

bool is_divisible_by_3(uint_fast32_t n) {
    uint_fast32_t aux = n%3;
    if (aux == 0) return true;
    if (aux == 2) return true; 
    return false;
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    uint_fast32_t casos; 
    std::cin >> casos;
    for (int i = 0; i < casos; i ++) {
        uint_fast32_t curr; 
        std::cin >> curr;
        if (is_divisible_by_3(curr)) {
            std::cout << "SI\n";
        }
        else std::cout << "NO\n";
    }
    return 0;
}