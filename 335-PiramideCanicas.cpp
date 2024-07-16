#include <iostream>
#include <cstdint>
/*
 * this result derives from sum_{i=1}^{h} i(i + 1)/2
 * which equas to the sum of every squered number 
 * until h and every natural number until h
 * */
int64_t pyramidHeigh (int64_t h) {
    int64_t marbles = 0;
    marbles = h*(h + 1)*(h+2) / 6;
    return marbles;
}

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos;
    int64_t h;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i) {
        std::cin >> h;
        std::cout <<  pyramidHeigh(h) << "\n";
    }
    return 0;
}
