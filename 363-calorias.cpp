#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int e, n, c;
    while (true) {
        int acum = 0;
        std::cin >> e;
        if (e == 0) return 0;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> c;
            acum += c;
        }
        int ne = acum / e + (acum - e*(acum/e) > 0);

        std::cout << ne << "\n";
    }
    
    return 0;
}
