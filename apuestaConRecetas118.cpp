/*https://aceptaelreto.com/problem/statement.php?id=118&potw=1*/

#include <iostream>
#include <algorithm>

/*existen 3 casos: 
Sea P el valor de la apuesta de pedro: 
    - P es mínimo: en este caso haremos perder al máximo (máximo es la apuesta máxima). Se debe cumplir que 
        $$(recibidasA + recibidasB + valorSalida)/3 - P < max - (recibidasA + recibidasB + valorSalida)/3$$
        Sólo puede ser este caso ya que, de ser la media mayor a Max, es imposible que pedro gane. En el peor caso, recibidosA y B serán valores máximos (64 por condición de enunciado). 
        Esto implica: 

        $$valorSalida = 3/2(P + max) - 128 = 1.5(P + max) - 128$$
            - Si valorSalida < 0 -> P pierde. La media puede ser mayor que max.
            - Si valorSalida > 64 -> max > p >= 128 => P le gana.  

        Si resulta en un valor decimal se debe tomar el menor, si resulta en un valor entero debemos restar 1.  

    - P es máximo: en este caso haremos perder al mínimo (min es la apuesta mínima). Se debe cumplir que
        $$ p - (recibidasA + recibidasB + valorSalida)/3 < (recibidasA + recibidasB + valorSalida)/3 - min$$.
        El peor caso es que recibidosA y B sean mínimos (0), lo que implica: 
        valorSalida = 3(P + Emin)/2 + 1( tomando en cuenta que / es la división entera)
            - Si valorSalida < 0 -> es imposible que se de 
            - Si valor > 64 -> P pierde

    - P es intermedio: P nunca pierde. a no ser que exceda 64. 
        A < P < B: 
            - Para los valores [A, P] => O gana A, o gana P, pero B siempre pierde. 
            - Para los valores [P, B] => O gana P, o gana B, pero A siempre pierde. 

    - P = A; P < B => haremos perder a B como en el primer caso. 
    - P = A; P > B => haremos perder a B como en el segundo caso.  
 

    */

inline int max_p_case(int p, int min);

inline int min_p_case(int p, int max);

inline int solution(int a, int b, int p) {
    int max, min;
    if ((a == b && a == p)) return 0; // si los tres son iguales
    
    if ([](int a, int b, int p){ // si p intermedio siempre gana 
        if (a > b) {
            return (a > p && p > b);
        }
        return (b > p && p > a);
    }(a, b, p)) {
        return 0;
    }
    // p maximo. Sabemos que a != b
    if (p >= a && p >= b) {
        min = std::min(a, b);
        return max_p_case(p, min);
    } else {
        max = std::max(a, b);
        return min_p_case(p, max);
    }
}

inline int max_p_case(int p, int min) {
    int value = static_cast<int>(1.5*(p + min)) + 1;
    if (value > 64) return -1;
    return value;
}

inline int min_p_case(int p, int max) {
    float fvalue = 1.5*(p + max) - 128; 
    if (fvalue < 0) return -1; // para cualquier valor de recibidasPedro la media puede estar por encima del valor intermedio
    if (fvalue > 64) return 0; // para cualquier valor de recibidasPedro la media estará más cerca de p. 
    return static_cast<int>(fvalue - 0.25); // si fvalue es entero => fvalue - 1. Sino, equivale a la función suelo. 
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int a, b, p;
    std::cin >> a >> b >> p; 
    while (a >= 0) {
        int evaluacion = solution(a, b, p); 
        if (evaluacion < 0)
        {
            std::cout << "I\n";
        }
        else {        
            std::cout << evaluacion << "\n";
        }
        std::cin >> a >> b >> p; 

    }
    return 0;
}