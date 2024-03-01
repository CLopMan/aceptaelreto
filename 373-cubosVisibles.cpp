#include <iostream>

int main() {

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos; 
    std::cin >> casos; 

    for (int i = 0; i < casos; ++i) {
        int64_t l;
        std::cin >> l;
        if (l == 1) std::cout << "1\n";
        else std::cout << l*l*l - (l - 2)*(l - 2)*(l - 2) << "\n";

    }


    return 0;
}