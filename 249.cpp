/* https://aceptaelreto.com/problem/statement.php?id=249 */


/*
// muy lentos 
#include <list> 
#include <algorithm>

std::list<int> leidos; 

long long int buscar_parejas(long long int burros, long long int sacos) {
    long long int peso = 0; 
    long long int cargados = 0;
    int in_peso;
    leidos.clear();
    while (burros > cargados && peso < sacos) {
        std::cin >> in_peso; 
        ++peso;
        auto pos = std::find(leidos.begin(), leidos.end(), in_peso);
        if (pos == leidos.end()) {
            leidos.push_back(in_peso);
        } else {
            ++cargados;
            leidos.erase(pos);
        }
    }
    while (peso++ < sacos) std::cin >> in_peso; 
    return cargados;

}

int main () {
    int casos;
    long long int burros, sacos; 
    std::cin >> casos; 
    for (int i = 0; i < casos; ++i) {
        std::cin >> burros >> sacos; 
        long long int out = buscar_parejas(burros, sacos);
        std::cout << out << "\n";
    }
    return 0;
}*/

#include <iostream>

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    bool repetidos[20000];
    int casos;
    int peso;
    long long int cargados;
    long long int burros, sacos; 
    std::cin >> casos; 
    for (int i = 0; i < casos; ++i) {
        cargados = 0; 
        for (int i = 0; i < 20000; ++i) repetidos[i] = false;
        std::cin >> burros >> sacos; 
        for (int i = 0; i < sacos; ++i) {
            std::cin >> peso; 
            repetidos[peso - 1] = !repetidos[peso - 1];
            if (cargados < burros && !repetidos[peso - 1]) ++cargados;
        }
        std::cout << cargados << "\n";
    }
    return 0;
}