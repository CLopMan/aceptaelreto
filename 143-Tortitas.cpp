#include <iostream>
#include <vector> 
#include <algorithm>

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    std::vector<int> tortitas; 
    tortitas.reserve(100);
    int t, vueltas, v;
    std::cin >> t; 
    while (t != -1) {
        tortitas.clear();
        while (t != -1) {
            tortitas.push_back(t); 
            std::cin >> t;
        }

        std::cin >> vueltas;
        for (int i = 0; i < vueltas; ++i) {
           std::cin >> v; 
           std::reverse(tortitas.end() - v, tortitas.end());
        }
        std::cout << tortitas[tortitas.size() - 1] << "\n";
        std::cin >> t;
    }
    return 0;
}
