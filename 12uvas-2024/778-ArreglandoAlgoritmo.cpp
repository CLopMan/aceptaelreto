#include <iostream>
#include <vector>

int main() {
    while (true) {
        int64_t max, curr, n;
        int count = 1;
        std::cin >> n;
        if (n == 0) break;
        std::cin >> curr;
        max = curr;
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> curr; 
            if (curr >= max) {
                max = curr;
                ++count;
            } else {
                count = 0;
            }
        }

        std::cout << count << "\n";
    }
        return 0;
}
