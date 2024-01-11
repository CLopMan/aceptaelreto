/*https://aceptaelreto.com/problem/statement.php?id=158&potw=1*/

#include <iostream> 

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    u_int32_t casos; 
    std::cin >> casos; 

    for (int i = 0; i < casos; ++i) {
        u_int32_t arriba = 0, abajo = 0, prev, curr, muros; 
        std::cin >> muros;

        for (int j = 0; j < muros; ++j) {
            
            if (j == 0) {
                std::cin >> curr; 
                prev = curr;
            } else {
                prev = curr; 
                std::cin >> curr; 
                if (curr > prev) arriba++;
                else if (curr < prev) abajo++;
            }
            
        }
        std::cout << arriba << " " << abajo << "\n"; 

        

    }

    return 0;
}