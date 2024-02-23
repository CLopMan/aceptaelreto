/*time limit exceed - needed segments trees */

#include <iostream>
#include <vector> 
#define MAX 500000

struct segment {
    int a;
    int b; 
};

bool in_segment(std::vector<segment> const &segments, int point) {
    for (auto s : segments) {
        if (point > s.a && point < s.b) {
            return true;
        }
    }
    return false;
}

int main() {

    std::vector<segment> segments;
    segments.reserve(MAX); 
    
    int sobrinos;
    while (std::cin >> sobrinos) {
        bool change = false; 
        int point;
        segments.clear();
        std::cin >> point;
        segments.push_back({point, point});
        for (int i = 1; i < sobrinos; ++i) {
            std::cin >> point; 
            if (change) continue;

            if (in_segment(segments, point)) {
                change = true; 
            } else {

                if (point > segments[segments.size() - 1].b) {
                    segments[segments.size() - 1].b = point;
                } else {
                    segments.push_back({point, point});
                    
                }
            }
        }

        if (change) std::cout << "ELEGIR OTRA\n";
        else std::cout << "SIEMPRE PREMIO\n";
    }

    return 0;
}