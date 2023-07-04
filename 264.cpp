/* https://aceptaelreto.com/problem/statement.php?id=264&potw=1 */
#include <iostream>
#include <cmath>


int base_number(int d) {
    return (sqrt(8*d + 1) - 1) / 2; 
}

int sum_elem(int b) {
    return (b*b + b)/2;
}

/*uint64_t tratar_caso(uint64_t d) {
    uint64_t base = base_number(d); 
    uint64_t pieces = sum_elem(base);
    uint64_t sub_pyramid = 0; 
    uint64_t new_base = 0;
    while (!pyramid) {
        sub_pyramid = sum_elem(++base) - d;
        new_base = base_number(sub_pyramid);
        
    }    

    return base - new_base;
}*/

int tratar_caso(int d) {
    int base = base_number(d); 
    int pieces = sum_elem(base);
    int i = 0, j = base;

    while (pieces != d) {
        if (pieces > d) {
            pieces -= ++i;
        } else if (pieces < d) {
            pieces += ++j;
        }
    }
    return j - i;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int d;
    while (std::cin >> d) {
        std::cout << tratar_caso(d) << "\n";
    }
    return 0; 
}
