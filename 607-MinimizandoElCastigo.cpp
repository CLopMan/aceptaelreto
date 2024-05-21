/* Este programa trata sólo de hacer el logaritmo en base 2 de la entrada */
#include <cmath>
#include <iostream>

int lg2(int n) {
    return static_cast<int>(std::ceil(std::log2(n)));
}


int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false); 
    int cases, n; 
    std::cin >> cases; 
    for (int i = 0; i < cases; ++i) {
        std::cin >>  n;
        std::cout << lg2(n) << "\n";
    }
    return 0;
}
