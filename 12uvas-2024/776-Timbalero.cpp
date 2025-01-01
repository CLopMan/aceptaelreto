#include <iostream>
#include <vector>

typedef struct {
    int begin;
    int end;
} intervalo;

int main() {
    while (true) {
        int pasajes, count = 0, no_platillos = 0;
        std::vector<intervalo> timbal; 
        std::cin >> pasajes;
        if (pasajes == 0) return 0;

        for (int i = 0; i < pasajes; ++i) {
            int b, e;
            std::cin >> b >> e;
            timbal.push_back({b, e});
        }
        int i = 0;
        int platillo;
        std::cin >> platillo; 
        while (true) {
            if (platillo == 0) break;
            if (i < timbal.size() && platillo >= timbal[i].begin && platillo <= timbal[i].end) {
                no_platillos++;
            };
            if (i < timbal.size() && platillo > timbal[i].end) ++i;
            else {
                std::cin>>platillo;
                count++;
            };
            
            
        }
        std::cout << count - no_platillos << "\n";

    }
    return 0;
}
