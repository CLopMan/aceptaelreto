#include <iostream>
#include <vector>
#include <algorithm>

struct sqr {
    int x;
    int y;
};
std::vector<bool> superVisited; 


bool _dfs(const std::vector<sqr> &cuadrados, int32_t w, int32_t h, sqr curr, std::vector<bool> &visited) {
    std::cout << "HEY.." << curr.x << "\n";
    if (curr.x + 20 >= w) return true;
    for (int i = cuadrados.size() - 1; i >= 0; --i) {
        auto s = cuadrados[i];
        if (visited[i] == false && (s.x >= curr.x && s.x <= curr.x + 20) && (s.y >= curr.y && s.y <= curr.y + 20)) {
            visited[i] = true;
            if (s.x == 0) superVisited[i] = true;
            bool result = _dfs(cuadrados, w, h, s, visited);
            if (result) return true;
            visited[i] = false;
        }
    }
    return false;


    
}

bool dfs(const std::vector<sqr> &cuadrados, int32_t w, int32_t h) {
    if (cuadrados[0].x > 0 ||  cuadrados[cuadrados.size() - 1].x + 20 < w) return false; 
    for (int i = 0; i < cuadrados.size(); ++i){
        if (cuadrados[i].x > 0) return false;
        if (superVisited[i] == false) {
            std::vector<bool> visited(cuadrados.size(), false);
            visited[i] = true;
            bool result = _dfs(cuadrados, w, h, cuadrados[i], visited);
            if (result) return result;
        }
        
    }
}


int main() {
    std::vector<sqr> cuadrados;
    cuadrados.reserve(1000); 
    superVisited.reserve(1000);

    while (1) {
        cuadrados.clear();
        int32_t w, h, n;
        std::cin >> w;
        if (0 == w) {
            break;
        }

        std::cin >> h >> n; 

        std::fill(superVisited.begin(), superVisited.begin() + n, false);

        for (int i = 0; i < n; ++i) {
            int32_t auxx, auxy;
            std::cin >> auxx >> auxy;
            cuadrados.push_back({(auxx - 10 > 0 ? auxx - 10 : 0), (auxy - 10 > 0 ? auxy - 10 : 0)});
        }
        
        std::sort(cuadrados.begin(), cuadrados.end(), [](sqr a, sqr b) {
            return a.x < b.x;
        });

        for (auto e : cuadrados) {
            std::cout << e.x << "\t" << e.y << "\n";
        }

        if (!dfs(cuadrados, w, h)) {
            std::cout << "SI\n";
        } else {
            std::cout << "NO\n";
        }




    }


    return 0;
}