/*https://aceptaelreto.com/problem/statement.php?id=685*/

#include <iostream> 

bool tratar_caso(int torre_x, int torre_y, int perro_x, int perro_y) {
    int v_x = abs(torre_x - perro_x), v_y = abs(torre_y - perro_y); 
    int aux; 
    if (v_y > v_x) {
        aux = v_x; 
        v_x = v_y; 
        v_y = aux;
    }
    aux = v_x - v_y; 
    if (aux == 0 || aux == v_x) {
        return true;
    }
    return false;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x1, y1, x2, y2; 
    std::cin >> x1 >> y1 >> x2 >> y2;
    while (x1 != 0 || x2 != 0 || y1 != 0 || y2 != 0){
        if (tratar_caso(x1, y1, x2, y2)) std::cout << "SI\n";
        else std::cout << "NO\n";
        std::cin >> x1 >> y1 >> x2 >> y2;
    }
    return 0;
}