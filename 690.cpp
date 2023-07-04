/* https://aceptaelreto.com/problem/statement.php?id=690 */
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    long int height = 1, width = 1; 
    char c;
    float area; 
    bool dentro; 
    std::cin >> width; 
    std::cin >> height; 
    while (height != 0 || width != 0) {
        area = 0;
        for (int h = 0; h < height; ++h) {
            dentro = false; 
            for (int w = 0; w < width; ++w) {
                std::cin >> c; 
                switch (c)
                {
                case '.':
                    if (dentro) area += 1;
                    break;
                case '/':
                    dentro = !dentro;
                    area += 0.5;
                    break;
                case '\\':
                    dentro = !dentro;
                    area += 0.5;
                    break;
                default:
                    break;
                }
            }
        }
        std::cout << area << "\n";
        std::cin >> width; 
        std::cin >> height; 
    } 
    return 0; 
}