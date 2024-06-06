//#include <stdio.h>
#include <iostream>

    int main() {
        int casos; 
        int n;
        std::cin >> casos; 
        for (int i = 0; i < casos; ++i) {
            std::cin >> n;
            std::cout << n/100 << "\n";
        }
        return 0;
    }