#include <iostream>
#include <string>

int darkSideTendency(int m) {
    int counter = 0;
    while(m != 0) {
        int remainder = m % 5;
        m = m / 5;
        if (4 == remainder) counter++;
        if (counter > 1) return 1;
    }
    return 0;
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos, miniclorianos;
    std::cin >> casos;

    while (casos--) {
        std::cin >> miniclorianos;
        if (darkSideTendency(miniclorianos)) {
            std::cout << "SI\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
