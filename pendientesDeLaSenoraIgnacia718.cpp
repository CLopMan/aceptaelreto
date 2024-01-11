#include <iostream> 
#include <unordered_set>

int main() {
    std::unordered_set<int> pendientes;
    int p, curr, cont;
    std::cin >> p;
    while (p > 0) {
        pendientes.clear();
        cont = 0;
        for (int i = 0; i < p; ++i) {
            std::cin >> curr; 

            if (pendientes.count(curr) > 0) {
                pendientes.erase(curr);
                cont++;
            }
            else pendientes.insert(curr);


        }

        std::cout << cont << "\n";

        std::cin >> p;
        
    }


    return 0; 
}