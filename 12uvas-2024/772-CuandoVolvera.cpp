#include <iostream>

int main() {
    int anno, avistamiento;
    while (true) {
        std::cin >> anno >> avistamiento;
        if (anno == 0 && avistamiento == 0) break;
        std::cout << "[" << anno + 74*avistamiento << " .. " << anno + 79*avistamiento << "]\n";
    }

    return 0;
}
