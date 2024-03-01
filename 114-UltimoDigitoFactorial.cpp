#include <iostream>

int fact[] = {1, 1, 2, 6, 4};

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos; 
    int n; 

    std::cin >> casos; 
    
    for (int i = 0; i < casos; ++i) {
        std::cin >> n;
        if (n < 5) std::cout << fact[n] << "\n";
        else std::cout << "0\n";


    }


    return 0;
}