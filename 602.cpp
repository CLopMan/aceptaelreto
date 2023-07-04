#include <iostream> 

int calculate_days(int n) {
    if (n == 1) {
        return 1;
    }
    int days = 2; 
    int money = 2; 
    int d1 = 1; 
    int d2 = 1;
    int aux; 
    while (money < n) {
        aux = d1 + d2*2;
        money += aux;
        d2 = d1; 
        d1 = aux;
        ++days;
    }
    return days;
}

int main() {
    int casos; 
    std::cin >> casos; 
    int n;
    for (int i = 0; i < casos; ++i) {
        std::cin >> n;
        std::cout << calculate_days(n) << "\n";
    }
    return 0;
}