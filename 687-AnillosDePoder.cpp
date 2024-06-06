/*https://aceptaelreto.com/problem/statement.php?id=687&potw=1*/

#include <iostream> 
#include <string>
#include <cinttypes>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int_fast16_t vertices, aristas = 0;
    std::string edge; 
    std::cin >> vertices; 
    while (vertices > 0) {
        edge = ""; 
        aristas = 0; 
        std::getline(std::cin, edge);
        std::getline(std::cin, edge);
        while (edge[0] != '0') {
            aristas++;
            std::getline(std::cin, edge);
        }
        std::cout << aristas + 1 - vertices << "\n";
        std::cin >> vertices;
    }
    return 0; 
}