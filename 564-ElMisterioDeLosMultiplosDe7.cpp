/*564: https://aceptaelreto.com/problem/statement.php?id=564 */

#include <iostream>

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int num_casos = 0;
    int N;
    std::cin >> num_casos; 

    for (int i = 0; i < num_casos; ++i) {
        std::cin >> N; 
        std::cout << N/3 << "\n";  
    }
    return 0;
}