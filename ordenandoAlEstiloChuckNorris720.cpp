#include <iostream> 

int main() {
    int ordered_elems;
    int n; 

    while (std::cin >> n) {
        ordered_elems = 0; 
        int64_t prev, curr;
        for (int i = 0; i < n; i++) {

            if (ordered_elems == 0) {
                ordered_elems++;
                std::cin >> prev;

            } else {
                std::cin >> curr;
                if (prev > curr) {
                    ordered_elems = 1;

                } else {
                    ordered_elems++;
                }
                prev = curr;
            }
            
        }
        int out = n;

        while (out > ordered_elems) {
            out = out / 2;
        }

        std::cout << out << "\n";
    }

    return 0;
}