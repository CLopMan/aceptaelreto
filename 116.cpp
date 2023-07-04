/* https://aceptaelreto.com/problem/statement.php?id=116 */
#include <iostream> 

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n; 
    std::cin >> n; 
    if (n == 1) {
        std::cout << "Hola mundo.\n";
    } else if (n == 2) {
        std::cout << "Hola mundo.\nHola mundo.\n";
    } else if (n == 3) {
        std::cout << "Hola mundo.\nHola mundo.\nHola mundo.\n";
    } else if (n == 4) {
        std::cout << "Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n";
    } else if (n == 5) {
        std::cout << "Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n";
    }
    return 0; 
}