#include <iostream>
#include <unordered_map>

int main() {
    while (true) {
        int64_t diseminacion = 0, n, curr;
        std::unordered_map<int64_t, int64_t> leds;
        
        std::cin >> n; 
        if (n == 0) return 0;
        
        for (int i = 0; i < n; ++i) {
            std::cin >> curr;
            if (leds.count(curr) > 0) diseminacion += i - leds[curr];
            leds[curr] = i;
        } 

        std::cout << diseminacion << "\n";
    
    }
    return 0;
}
