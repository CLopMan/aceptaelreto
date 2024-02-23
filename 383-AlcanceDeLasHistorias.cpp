#include <iostream>

int main() {
    
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    int casos; 
    std::cin >> casos; 


    for (int i = 0; i < casos; ++i) {

        int pivote, n_paginas, pagB, best;
        std::cin >> n_paginas >> pivote >> pagB; 
        best = pivote - pagB;
        pivote = std::max (pivote, pagB);


        for (int j = 2; j < n_paginas; ++j) {
            std::cin >> pagB;
            best = std::max(pivote - pagB, best);
            pivote = std::max (pivote, pagB);

        }
        std::cout << best << "\n";

    }

    return 0;
}