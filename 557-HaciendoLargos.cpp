#include <iostream> 

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int casos;
    std::cin >> casos;

    while (casos--) {
        int64_t N, T, M, D, I;
        std::cin >> N >> T >> M >> D >> I;
        int64_t x = N/M + (N % M ? 0 : -1);
        std::cout << N * T + x * D + I * (x*(x - 1))/2 << "\n";
    }

    return 0;
}