#include <iostream> 

int main() {
    int N;
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> N;
    while (N > 0) {

        int64_t sum = 0; 
        for (int i = 0; i < N; ++i) {
            int aux; 
            std::cin >> aux; 
            sum += aux;
        }
        std::cout << sum << "\n"; 
        std::cin >> N;
    }

    return 0; 
}