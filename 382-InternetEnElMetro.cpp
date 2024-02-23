#include <iostream> 

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int casos; 
    int distance; 
    int antenas;

    std::cin >> casos; 

    for (int i = 0; i < casos; ++i) {
        int most_right = 0; 
        int pos, r;
        std::cin >> distance >> antenas; 

        for (int j = 0; j < antenas; ++j) {
            std::cin >> pos >> r; 

            if (pos - r <= most_right) {
                most_right = std::max(most_right, pos + r);
            }
        }
        if (most_right >= distance) std::cout << "SI\n";
        else std::cout << "NO\n";


    }


    return 0;
}