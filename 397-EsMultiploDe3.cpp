/*https://aceptaelreto.com/problem/statement.php?id=397&potw=1*/

#include <iostream>
#include <stdint.h>

/*
Primero debemos tener en cuenta el siguiente resultado: la suma de dos números consecutivos NO divisibles entre 3, será divisible entre 3. 

Con esto en mente, es sencillo darse cuenta de que los números naturales seguirán el siguiente patrón respecto a su suma: 
1 -> no se divide entre 3
12 -> divisible entre 3
123 -> divisible entre 3
1234 -> no divisible entre 3
12345 -> divisible entre 3
123456 -> divisible entre 3
1234567 -> no divisible entre 3

Y así sucesivamente. 

Cuando alcanzamos los números de dos cifras, seguimos el mismo patrón ya que 10 equivale a 1 (1 + 0 = 0), 11 a 2, 12 a 3... 19 a 1, 20 a 2, 21 a 3... 28 a 1, 29 a 2...

Esto último, para verlo con más calma: 

29 => 2 + 9 = 11. 11 mod 3 = 2

Por tanto, tan sólo nos interesa saber si el conjunto de los N números (donde N es la entrada) se puede agrupar por tríos: 
    - Si sobra 1 número => no es divisible
    - Si sobran 2 personas o ninguna => es divisible. 

*/

bool is_divisible_by_3(uint_fast32_t n) {
    uint_fast32_t aux = n%3;
    if (aux == 0) return true;
    if (aux == 2) return true; 
    return false;
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    uint_fast32_t casos; 
    std::cin >> casos;
    for (int i = 0; i < casos; i ++) {
        uint_fast32_t curr; 
        std::cin >> curr;
        if (is_divisible_by_3(curr)) {
            std::cout << "SI\n";
        }
        else std::cout << "NO\n";
    }
    return 0;
}