#include <iostream> 

int main() {

    int32_t casos; 

    std::cin >> casos; 

    for (int i = 0; i < casos; i++) {
        int32_t uvas, personas;
        std::cin >> uvas >> personas;  
        if (uvas / 12 >= personas) std::cout << "SI\n";
        else std::cout << "NO\n";
    }

    return 0;
}