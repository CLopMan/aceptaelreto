#include <stdio.h>
#include <iostream> 

int main() {
    int anno;
    std::cin >> anno;
    while (anno > 0) {
        int cantidades[10];
        int apariciones[] = {0,0,0,0,0,0,0,0,0,0};

        int d0 = anno % 10;
        ++apariciones[d0];
        int d1 = (anno / 10) % 10;
        ++apariciones[d1];

        int d2 = (anno / 100) % 10;
        ++apariciones[d2];

        int d3 = (anno / 1000) % 10;
        ++apariciones[d3];

        int digits[] = {d0, d1, d2, d3};

        int in; 
        for (int i = 0; i < 10; ++i) {
            std::cin >> in; 
            cantidades[i] = in;
        }
        int out = cantidades[d0] / (3 * apariciones[d0]);
        for (int i = 1; i < 4; ++i) {
            int digit = digits[i];
            int comp = cantidades[digit] / (3 * apariciones[digit]);
            if (comp < out) {
                out = comp;
            }
        }
        std::cout << out << "\n";
        std::cin >> anno;
    }
    return 0;
}
