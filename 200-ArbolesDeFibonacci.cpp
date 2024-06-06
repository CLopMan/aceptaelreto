/* https://aceptaelreto.com/problem/statement.php?id=200 */
#include <iostream>
#include <stdio.h> 
#include <vector> 

std::vector<int> fibonacci; 
int max_cal = 1; 
void fibonacci_till_n(int n) {
    if (n > max_cal) {
        for (int i = max_cal + 1; i <= n; ++i) {
            fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
        }
       max_cal = n;  
    }
}

void print_fib_tree(int n, int spaces) {
    if (n == 1 || n == 0) {
        std::cout << fibonacci[n] << "\n";
    } else {
        std::cout << fibonacci[n] << "\n";
        for (int i = 0; i < spaces*3; ++i) std::cout << " ";
        print_fib_tree(n - 2, spaces + 1);
        for (int i = 0; i < spaces*3; ++i) std::cout << " ";
        print_fib_tree(n - 1, spaces + 1);
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    int n; 
    std::cin >> n; 
    while (n >= 0) {
        fibonacci_till_n(n); 
        print_fib_tree(n, 1);
        std::cout << "====\n";
        std::cin >> n; 
        
    }
    return 0;
}