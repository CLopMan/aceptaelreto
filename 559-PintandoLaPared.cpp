/*https://aceptaelreto.com/problem/statement.php?id=559*/

#include <iostream> 
#include <algorithm>
#include <vector>
#include <set>

#define MAX_STROKES 1000

typedef struct point64_t {
    int64_t x;
    int64_t y;
} flecha;

/*void print64_t_vector(std::vector<flecha> vector) {
    for (int64_t i = 0; i < vector.size(); ++i) {
        std::cout << "(" << vector[i].x << ", " << vector[i].y << "); ";
    }
    std::cout << "\n";
}*/

bool comp(const flecha& a, const flecha& b) {
    return a.x < b.x;
}

int64_t area_calculator(std::vector<flecha> map, int64_t width, int64_t n_strokes) {
    std::sort(map.begin(), map.end(), comp);
    std::multiset<int64_t> stack = { 0 };
    std::vector<flecha> skyline;
    int64_t h = 0;
    for (auto w : map) {
        if (w.y > 0) {
            stack.insert(w.y);
        } else 
            stack.erase(stack.find(-w.y));

        if (*stack.rbegin() != h) {
            h = *stack.rbegin();
            flecha aux;
            aux.x = w.x;
            aux.y = h;
            skyline.push_back(aux);
        }
    }
    int64_t area = 0; 
    int64_t lastX = skyline[0].x, lastY = skyline[0].y;
    for (int64_t i = 1; i < skyline.size(); ++i) {
        area += (skyline[i].x - lastX)*lastY;
        lastX = skyline[i].x;
        lastY = skyline[i].y;
    }
    
    
    return area;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int64_t width, n_strokes, x, y, lastx, lasty; 
    std::cin >> width;
    flecha subida, bajada;
    std::vector <flecha> map;
    while (width > 0) {
        std::cin >> n_strokes;
        map.clear();
        for (int64_t i = 0; i < n_strokes; ++i) {
            int64_t x, y; 
            std::cin >> x >> y; 
            subida.x = x;
            subida.y = y;
            bajada.x = x + width; 
            bajada.y = -y;
            map.push_back(subida);
            map.push_back(bajada);
        }
        std::cin >> width;
        std::cout << area_calculator(map, width, n_strokes) << "\n";
    }
    return 0;
}