/*https://aceptaelreto.com/problem/statement.php?id=643&potw=1*/

#include <iostream> 

#define MAX_BAG_SIZE 1e7

typedef struct basura {
    int size;
    char type;
} basura; 

bool trash_simulation (basura* restos, int residuos, int size, int salidas) {
    bool print = false;
    if (size == 453) print = true;
    int envases = 0, general = 0;
    basura _resto;
    for (int i = 0; i < residuos; i++) {
        _resto = restos[i];
        if (_resto.type == 'E') {
            envases += _resto.size;
        } else general += _resto.size;

        if (general > size || envases > size*2) {
            if (_resto.type == 'E') {
                envases = _resto.size;
                general = 0;
            } else {
                envases = 0; 
                general = _resto.size;
            }
            
            salidas--; 
        }

        if (salidas < 0) break;
        if (print) std::cout << "envases " << envases << "\tresiduos " << general << "\tsalidas " << salidas << "\n";
    }
    if (general > 0 || envases > 0) salidas--;


    return !(salidas < 0);
}

int binary_search_size(int min, int max, basura* restos, int residuos, int salidas) {
    int out;

    while(min != max) {
        out = (min + max) / 2;
        if (trash_simulation(restos, residuos, out, salidas)) {
            max = out;
        } else {
            min = out + 1;
        }

    }
    return min; 
}

int minimun_capacity(int salidas, int residuos) {
    int capacidad;
    basura restos[200000];
    int tamanno, max_size = 0; 
    char tipo;  

    // leer la entrada y sacar el maximo de los tamaños (min en binary search)
    for (int i = 0; i < residuos; ++i) {
        basura resto;
        std::cin >> tamanno >> tipo; 

        resto.size = tamanno;
        resto.type = tipo; 
        restos[i] = resto;
        if (tipo == 'E') {
            if (max_size*2 < tamanno){
                if (tamanno % 2) max_size = tamanno / 2 + 1; 
                else max_size = tamanno/2;
            }
        } else if (max_size < tamanno) max_size = tamanno; 
    }
        
    capacidad = binary_search_size(max_size, MAX_BAG_SIZE, restos, residuos, salidas); 

    return capacidad;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int salidas, residuos; 
    std::cin >> salidas >> residuos; 
    while (salidas != 0 || residuos != 0) {

        std::cout << minimun_capacity(salidas, residuos) << "\n";
        std::cin >> salidas >> residuos;
    }
    return 0;
}