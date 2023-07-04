/* https://aceptaelreto.com/problem/statement.php?id=312 */
#include <iostream>

int64_t gcd(int64_t a, int64_t b) {
    int64_t aux;
    if (a < b) {
        aux = b;
        b = a;
        a = aux;
    }
    if (b == 0) return a;
    //std::cout << "pito\n";
    while ((a % b) != 0) {
        //printf("a: %lli, b: %lli, a%%b: %lli", a, b, a%b);
        aux = b;
        b = a % b;
        a = aux;
    }
    return b;
}

int main () {
    int64_t input;
    int64_t sum = 0; 
    int64_t d = 0;
    int exit = 0;

    while (!exit) {
        //std::cout << "here  we go\n";
        sum = 0;
        d = 0;
        std::cin >> input;
        sum += input;
        exit = 1;
        while (input != 0) {
            d = gcd(input, d);
            std::cin >> input;
            sum += input;
            exit = 0;
        }
        if (exit) return 0; 
        int64_t out = sum/d;
        std::cout << out << "\n";
    }
    
    
    return 0;
}