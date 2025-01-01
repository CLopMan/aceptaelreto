#include <iostream>
#include <vector>

int main() {
    while (true) {
        int limit, tipos, curr, acum = 0;
        std::vector<int> polv_tipo;
        std::cin >> limit >> tipos;
        
        bool limit_tipo = false, limit_cant = false;

        if (limit == 0 && tipos == 0) return 0;

        for (int i = 0; i < tipos; ++i) {
            std::cin >> curr; 
            polv_tipo.push_back(curr);
        }
        for (int i = 0; i < tipos; ++i) {
            std::cin >> curr;
            if (curr > polv_tipo[i]) limit_tipo = true;
            acum += curr;
        }
        
        if (acum > limit || limit_tipo) std::cout << "NO\n";
        else std::cout << "SI\n";
    } 
    return 0;
}
