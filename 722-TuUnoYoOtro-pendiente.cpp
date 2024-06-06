#include <iostream> 

#define d (a*a - b*b)

int main() {
    int64_t c1, c2, a, b;

    std::cin >> c1 >> c2 >> a >> b; 

    while(c1 != 0) {
        

        //std::cout << x << " " << y << "\n";
        
        if(a == b) {
            if (c1 == c2 && c1 % a == 0) std::cout << "SI\n";
            else std::cout << "NO\n";
        } else 
        {
            int64_t x = (a * c2 - b*c1) / d;
            int64_t y = (a * c1 - b*c2) / d;
            if (a*y + b*x == c1 && a*x + b*y == c2) std::cout << "SI\n";
            else std::cout << "NO\n";
        }
        std::cin >> c1 >> c2 >> a >> b; 



    }

    return 0;
}