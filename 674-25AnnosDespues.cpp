#include <stdio.h>
#include <iostream>
int64_t n0_fact(int64_t n) {
    int64_t div5 = n/5;
    int64_t out = 0;
    while (div5 > 0) {
        out += div5;
        div5 /= 5;
    }
    return out;
}

int64_t busquedaCeros(int64_t n) {
    if (n == 0) {
        return 1;
    }
    int64_t max = 1e13;
    int64_t min = 1;
    int64_t pivote;
    while (max > min) {
        pivote = (max + min)/ 2;
        //std::cout << "max: " << max << " " << "min: " << min << " " << "pivote: " << pivote << " " << "\n";
        int64_t n_pivote = n0_fact(pivote);
        if (n == n_pivote) {
            int64_t out = pivote;
            while (n0_fact(pivote) == n) {
                out = pivote;
                pivote -= 1;
            }
            //printf("out: %i\n", out);
            return out;
        }
        if (n > n_pivote) {
            min = pivote + 1;
        } else {
            max = pivote - 1;
        }
    }
    // no existen facoriales con n ceros consecutivos
    return -1;
}

int main() {
    int64_t d;
    int64_t n; 
    std::cin >> d >> n;
    while (d != 0 || n != 0) {
        // std::cout << busquedaCeros(n) << "\n";
        int64_t candidato = busquedaCeros(n);
        if (candidato == -1){
            std::cout << "NINGUNO\n";
        } else {
            int resto = candidato % d;
            if (resto == 0) {
                std::cout << candidato << "\n";
            } else if (n0_fact(candidato + (d - resto)) == n){
                std::cout << candidato + (d - resto) << "\n";
            } else {
                std::cout << "NINGUNO\n";
            }
        }
        
        std::cin >> d >> n;
        
    }
}
