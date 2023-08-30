/*https://aceptaelreto.com/problem/statement.php?id=244*/

#include <iostream>
#include <string>
#include <vector> 

std::vector<std::pair<int, int>> coords;

std::string evaluate_table(int table_size, int n_queens) {
    bool threat = false;
    for(int i = 0; i < n_queens; ++i) {
        std::pair<int, int> curr_queen;
        std::cin >> curr_queen.first >> curr_queen.second;
        if (!threat) {
            for (auto v : coords) {
                int diff_x = abs(v.first - curr_queen.first);
                int diff_y = abs(v.second - curr_queen.second);
                int diff = diff_x - diff_y;
                if (diff == 0 || diff == diff_x || diff == -diff_y) threat = true;
            }
            coords.push_back(curr_queen);
        }
    }
    if (threat) return "SI";
    return "NO";
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int table_size, n_queens, i = 0;
    std::cin >> table_size >> n_queens;
    while (table_size != 0 || n_queens != 0) {
        coords.clear();
        std::cout << evaluate_table(table_size, n_queens) << "\n";
        std::cin >> table_size >> n_queens;
    }
    return 0;
}