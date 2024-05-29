#include <iostream> 

int main() {
    int bases, necesario, bajas, retaguardia, sum, max; 

    std::cin >> bases; 

    while (bases > 0) {
        sum = 0; 
        for (int i = 0; i < bases; ++i) {
            std::cin >> necesario >> bajas >> retaguardia;
            sum += bajas + retaguardia;
            max = std::max(max, std::max(sum, necesario));   
        }
        std::cout << max << "\n";

        std::cin >> bases;
    }

    return 0; 
}