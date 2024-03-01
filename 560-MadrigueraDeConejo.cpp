#include <iostream> 
#include <vector>
#include <numeric>

int64_t addUpDistance(int n) {
    std::vector<int> holes(21, 0);
    int64_t d = 0; 
    for (int i = 0; i < n; ++i) {
        d = std::accumulate(holes.begin(), holes.end(), d);
        int h; 
        std::cin >> h; 
        ++holes[h];
        std::fill(holes.begin(), holes.begin() + h, 0);
    }
    return std::accumulate(holes.begin(), holes.end(), d);

}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n; 

    std::cin >> n;

    while(n > 0) {
        int64_t d = addUpDistance(n);
        std::cout << d << "\n"; 
        std::cin >> n;
    }


    return 0;
}