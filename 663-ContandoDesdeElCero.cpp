#include <stdio.h>
#include <iostream> 

int main() {
    int casos;
    std::cin >> casos;
    for (int i=0; i < casos; ++i) {
        int ano; 
        std::cin >> ano; 
        if (ano > 0) {
            ano = ano - 1;
        }
        std::cout << ano << "\n";
    }
    return 0;
}
