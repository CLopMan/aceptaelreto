#include <iostream> 

int main() {
    int regletas = 1, enchufes, holes;
    std::cin >> regletas; 

    while (regletas > 0) {
        holes = 1;

        for (int i = 0; i < regletas; ++i) {
            std::cin >> enchufes;
            holes += enchufes;

        }
        std::cout << holes - regletas << "\n";
        std::cin >> regletas; 

    }

    return 0; 
}