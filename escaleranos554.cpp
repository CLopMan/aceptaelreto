/*https://aceptaelreto.com/problem/statement.php?id=554*/

/*
Dado un número N, para saber las forma distintas de sumarlo con p1, p2, p3...pn entonces:

La respuesta es  formas de sumar N - pa + formas de sumar N - pb ..... 

Hasta un número a < min(pa, pb, pc..) => rama no válida
a = min(pa, pb, pc) => 1 

*/

#include <iostream> 
#include <vector>
#include <algorithm>

std::vector<int32_t> calculated(101, -1); 
constexpr int32_t mod = 1000000007;

int32_t _escaleranos(int N, const std::vector<int> &steps) {
    if (N == 0) {
        return 1;
    }

    if (N < *std::min_element(steps.begin(), steps.end())) {
        return 0;
    }
    int32_t acum = 0;
    for (int i : steps) {
        if (N - i > 0 && calculated[N - i] != -1) acum += calculated[N - i];
        else 
            acum += _escaleranos(N - i, steps) % mod;
            acum %= mod;

    }
    calculated[N] = acum;
    return acum;


    
}



int32_t escaleranos(int N, const std::vector<int> &steps) {
    if (calculated[N] != -1) return calculated[N];
    calculated[N] = _escaleranos(N, steps);
    return calculated[N];

}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N, argc;
    std::vector<int> p;

    std::cin >> N;
    while (N > 0) {
        p.clear();
        std::cin >> argc;
        for (int i = 0; i < argc; i++ ) {
            int aux; 
            std::cin >> aux;
            p.push_back(aux);
        }
        for (int i = 1; i < 101; ++i) {
            calculated[i] = -1;
        }
        std::cout << escaleranos(N, p) << "\n";
        std::cin >> N;

    }

    return 0;
}