#include <iostream>

int64_t n_vueltas (int64_t n) {
    if (n <= 3599) {
        return n;
    }
    int64_t  out = 0;
    int64_t aux;
    while(n >= 3600) {
        aux = 3600*(n/3600);
        out += aux;
        n -= aux - n/3600;
        //std::cout << "n: " << n << " out: " << out << "\n";
    }
    return out + n;
}

int main() {
    int casos;
    int64_t n;
    std::cin >> casos; 
    for (int i = 0; i < casos; ++i) {
        std::cin >> n; 
        std::cout << n_vueltas(n) << "\n";

    }
    return 0;
}
