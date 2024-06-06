/*https://aceptaelreto.com/problem/statement.php?id=433&potw=1*/

#include <iostream> 
#include <cmath> 

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N, out, n; 
    std::cin >> N; 
    while (N > 0) {
        n = (sqrt(8*N + 1) - 1)/2;
        if (n*(n + 1)/2 < N) n++;
        std::cout << n << "\n";
        std::cin >> N;
    }
    return 0; 
}