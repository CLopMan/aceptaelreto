#include <iostream> 

int gcd(int a, int b) {

    while (b != 0) {
        int res = a % b; 
        a = b; 
        b = res;
    }
    return a;
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n_planets;
    int a;

    std::cin >> n_planets;
    while (n_planets > 0) {
        a = 1;
        int mcm = 1;
        for (int i = 0; i < n_planets; ++i) {
            std::cin >> a;
            mcm = lcm(mcm, a);
        }
        std::cout << mcm << "\n";
        std::cin >> n_planets;
    }

    return 0;
}