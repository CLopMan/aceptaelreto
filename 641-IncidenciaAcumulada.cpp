/* https://aceptaelreto.com/problem/statement.php?id=641 */
#include <iostream> 
#include <vector> 

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    long long int len, known_days;
    long long int current_acum, max_acum; 
    long long int current, past_pos, next_pos; 
    std::vector<int> input; 
    std::cin >> len >> known_days;
    while (len != 0 || known_days != 0) {
        current_acum = 0;
        max_acum = 0; 
        past_pos = 0;
        input.clear();
        next_pos = len;
        for (int i = 0; i < known_days; ++i) {
            std::cin >> current; 
            input.push_back(current);
            if (i < len) {
                current_acum += current;
            }
        }
        max_acum = current_acum; 
        while (next_pos < known_days) {
            current_acum -= input[past_pos++];
            current_acum += input[next_pos++];
            if (current_acum > max_acum) max_acum = current_acum;
        }
        std::cout << max_acum << "\n";
        std::cin >> len >> known_days;
    }
    return 0;
}