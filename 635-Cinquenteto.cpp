#include <iostream>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos; 
    std::cin >> casos;
    for (int i = 0; i < casos; ++i) {
        int year;
        std::cin >> year;
        int century = year / 100;
        if (year % 100 > 0) ++century;

        std::cout << century << "\n";
    }
    

    return 0;
}