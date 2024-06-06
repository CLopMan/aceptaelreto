#include <stdio.h>
#include <iostream>
#include <algorithm>


int matrix[20001];

/*int add5_mul3(int n){
    //recursiva
    if (n <= 0) {
        return 0;
    }
    if (matrix[n] != -1) {
        return matrix[n];
    matrix[n] = add5_mul3(n - 5) || (n % 3 == 0 && add5_mul3(n / 3));
    return matrix[n];
    
}*/

int add5_mul3(int n, int last) {
    // iterativa 
   if (matrix[n] != -1) {
        return matrix[n];
   }
    int start = last + 1;

    for (start; start < n + 1; ++start) {
        matrix[start] = (start % 3 == 0 && matrix[start / 3]) || (start - 5 >= 0 && matrix[start - 5]);
    }
    return matrix[n];
}


int main() {
    matrix[1] = 1;
    matrix[0] = 0;
    int last = 1;
    for (int i=2; i < 20001; ++i) {
        matrix[i] = -1;
    }
    int input; 
    std::cin >> input;
    while (input != 0) {
        
        if (add5_mul3(input, last)) {
            std::cout << "SI" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
        if (input > last) {
            last = input;
        }

    std::cin >> input;
    }
    return 0;
}