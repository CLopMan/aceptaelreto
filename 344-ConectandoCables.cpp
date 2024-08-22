#include<iostream>
#include<string>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int casos;
    std::cin >> casos; 

    while (casos--) {
        int cables, countH = 0, countM = 0;
        std::string c;
        std::cin >> cables;
        for (int i = 0; i < cables; ++i) {
            std::cin >> c;
            for (auto s : c) {
                if (s == 'H') ++countH;
                else ++countM;
            }
        }

        if (countM != countH) std::cout << "IMPOSIBLE\n";
        else std::cout << "POSIBLE\n"; }
    return 0;
}
