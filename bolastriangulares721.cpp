#include <iostream> 

int main() {
    int last_row; 
    int acum; 
    int next_package; 
    int casos; 
    int n, offset;

    std::cin >> casos; 
    for (int i = 0; i < casos; ++ i) {
        last_row = 1; 
        acum = 0; 
        next_package = 1; 
        std::cin >> n; 
        offset = n; 

        while (offset >= next_package) {
            last_row++; 
            offset -= next_package;
            next_package += last_row; 
            acum++;
        }

        std::cout << acum << "\n";


    }
    
    return 0;
}