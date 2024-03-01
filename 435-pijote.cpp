#include <iostream> 


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    char number[1000];
    int count[10];
    bool control = true;
    while (std::cin >> number) {
        control = true;
        for (int i = 0; i < 10; ++i) {
            count[i] = 0;
        }

        char c = ' ';
        int i = 0;
        while (c != '\0') {
            c = number[i++];
            ++count[c - '0']; 
        }

        for (int i = 1; i < 10; ++i) {
            if (count[i] != count[i - 1]) {
                std::cout << "no subnormal\n";
                control = false;
                break;
            
            }

        }
        if (control) std::cout << "subnormal\n";

    }

    return 0;
}