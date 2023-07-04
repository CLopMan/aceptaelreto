/* https://aceptaelreto.com/problem/statement.php?id=139 */
#include <iostream> 
#include <vector> 

long long int sumSquereDigits(long long int n) {
    long long int acum = 0;
    while (n != 0) {
        long long int d = n%10;
        acum += d * d * d; 
        n /= 10; 
    }
    return acum;
}
int caso(long long int n) {
    if (n == 0) return 0; 
    std::vector<int> secuencia; 
    bool repetido = false; 
    std::cout << n << " -";
    secuencia.push_back(n);
    while (n != 1 && !repetido) {
        n = sumSquereDigits(n); 
        std::cout <<" " << n << " -";
        for (int i = 0; i < secuencia.size(); ++i) {
            if (n == secuencia[i]){
                repetido = true; 
                break; 
            }
        }
        secuencia.push_back(n);

        
        
        
    }
    if (repetido) {
        std::cout << "> no cubifinito.\n";
    } else {
        std::cout << "> cubifinito.\n";
    }
    return 1;
}

int main() {
    long long int n; 
    std::cin >> n; 
    while (caso(n) != 0) std::cin >> n; 
    return 0;
}