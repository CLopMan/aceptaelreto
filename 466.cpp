#include <iostream>
#include <string.h> 
int out[101];

void weirdProduct(char* a, char* b, int* longitud_final) {
    
    int len_a = strlen(a) - 1; // # cifras del primer número
    int len_b = strlen(b) - 1; // # cifras del segundo número

    int mul_a = (a[len_a] - '0'); // cifra para multiplicar del primer número
    int mul_b = (b[len_b] - '0'); // cifra para multiplicar del segundo número
    int digit = 0; // cifra a añadir al nuevo número
    int index = 0; // donde debe añadirse la nueva cifra
    if (mul_a == 0 && mul_b == 0 && len_a == 0 && len_b == 0) { //si me llega el 0
        out[0] = 0;
        ++(*longitud_final);
        return ;
    }
    while (len_a >= 0 || len_b >= 0) {
        
        digit += mul_a*mul_b;
        //printf("len_a: %i, len_b: %i, index: %i, longitud_final: %i, sum: %i * %i, digit: %i\n", len_a, len_b, index, *longitud_final, mul_a, mul_b, digit);
        out[index] = digit %10;
        //std::cout << out[index] << "\n";
        digit /= 10;

        ++(*longitud_final);
        --len_a; --len_b; ++index;
        //std::cout << digit << " " << len_a << " " << len_b<< "\n";
        if (len_a >= 0) {
            mul_a = (a[len_a] - '0');
        } else mul_a = 0;

        if (len_b >= 0) {
            mul_b = (b[len_b] - '0');
        } else mul_b = 0;
    }
    //printf("len_a: %i, len_b: %i, index: %i, longitud_final: %i, sum: %i * %i, digit: %i\n", len_a, len_b, index, *longitud_final, mul_a, mul_b, digit);

    //acarreo del último
    if (digit > 0) {
        out[index] = digit;
        ++(*longitud_final);
    }
}

int main() {
    int casos;
    std::cin >> casos; 
    char a[101], b[101]; 
    for (int i = 0; i < casos; ++i) {
        int longitud_final = 0;
        

        std::cin >> a >> b;
        weirdProduct(a, b, &longitud_final);
        //std::cout << "out: ";
        for (int j = longitud_final - 1; j >= 0; --j) {
            std::cout << out[j];
        }
        std::cout << "\n";
    }
    return 0;
}