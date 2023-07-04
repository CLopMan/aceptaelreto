#include <iostream>

int main() {
    int puentes; 
    std::cin >> puentes;
    int carriles;
    

    while (puentes > 0){
        int altura = 0;
        int compare_altura;
        int out = 801;
            
        for (int j = 0; j < puentes; ++j) {

            // maximo de la fila
            std::cin >> carriles;

            for (int i = 0; i < carriles; ++i) {
                std::cin >> compare_altura;
                if(compare_altura > altura) {
                    altura = compare_altura;
                }
            }

            // menor entre filas
            if (altura < out) {
                out = altura;
            }
            altura = 0;

        }
        std::cout << out << "\n";
        std::cin >> puentes;


    }

    return 0;
}