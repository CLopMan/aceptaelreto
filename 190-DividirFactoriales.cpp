#include <iostream>

long long int div_fact(long int n1, long int n2) {
    long long int out = 1;
    for (int i = n1; i > n2; --i) {
        out *= i;
    }
    return out;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    long int a, b; 
    std::cin >> a >> b; 
    while (a >= b) {
        std::cout << div_fact(a, b) << "\n";
        std::cin >> a >> b;
    }
    return 0;
}