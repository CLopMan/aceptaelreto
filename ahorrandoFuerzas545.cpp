/*https://aceptaelreto.com/problem/statement.php?id=545&potw=1*/

/*En general, tenemos que x = v(t - a)
    - x := distancia a recorrer
    - v := velocidad del vehículo
    - a :=  isntante de tiempo en el que pasa el vehículo respecto a Marty

El tiempo que tarda el vehículo i en llegar a x viene dado por la expresión
t_i = x/v + a. 
    
Si a < 0 => no debemos tener en cuenta ese valor: 
    - Si el vehículo es más rápido que el próximo que llegue, no lo alcanzaremos y Marty no se podrá agarrar. 
    - SI el vehículo es igual de rápido que el próximo que llegue, idem con el anterior
    - Si el vehículo es más lento: 
        - Puede que no lo alcance por diferencia de distancias
        - Si lo adelanto, no me cambio de vehículo. 

para los demás, debemos coger el t_i más bajo. 
    
    
*/

#include <iostream>

int instante(int x, int v, int a) {
    //if (v <= 0) return __INT_MAX__;
    return x/v + a;
}

int main() {
    std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
    int distancia, n_coches;
    
    while (std::cin >> distancia >> n_coches) {
        int min = __INT_MAX__, curr_t;
        int vel, a;
        
        for (int i = 0; i < n_coches; ++i) {
            std::cin >> a >> vel;
            if (a >= 0) {
                curr_t = instante(distancia, vel, a);
                min = (curr_t < min) ? curr_t : min;
            }
        }
        std::cout << min << "\n";
    }


    return 0;
}