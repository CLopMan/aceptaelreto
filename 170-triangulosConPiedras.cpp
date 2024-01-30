/*https://aceptaelreto.com/problem/statement.php?id=170&cat=40*/

#include <iostream> 
#include <cmath>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int entrada; 
    std::cin >> entrada;
    while (entrada > 0) {
        int lado = (int)(-0.5 + 0.5*sqrt(1 + 8*entrada));
        std::cout << lado << " " << entrada - lado*(lado + 1)*0.5 << "\n";
        std::cin >> entrada;
    }

    return 0;
}