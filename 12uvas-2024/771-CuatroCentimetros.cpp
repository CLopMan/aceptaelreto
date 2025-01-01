#include <iostream>

int main() {
    int casos, annos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i) {
        std::cin >> annos;
        std::cout << annos * 4 << "\n";
    }

    return 0;
}
