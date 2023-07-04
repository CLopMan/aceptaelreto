/*https://aceptaelreto.com/problem/statement.php?id=699*/

#include <iostream>
#include <vector>

bool first = true;


void print_term(int coeficiente, int exp) {
    if (first) {
        if (exp <= 0 || coeficiente == 0) printf("%i", coeficiente);
        else if (exp == 1) {
            if (coeficiente != 1) {
                printf("%ix", coeficiente);
            } else printf("x");
        } else printf("%ix^%i", coeficiente, exp); 
    } else {
        if (coeficiente != 0) {
            printf("+"); 
            if (exp <= 0) printf("%i", coeficiente);
            else if (exp == 1) {
                if (coeficiente != 1) {
                    printf("%ix", coeficiente);
                } else printf("x");
            } else printf("%ix^%i", coeficiente, exp); 
        }
    }
    first = false;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    char aux[4];
    int coeficiente;
    int exp;
    char c; 
    int i = 0; 
    int state = 0; 
    while ((c = getc(stdin)) != EOF) {
        //printf("c : %c state: %i\n", c, state);
        switch (state)
        {
        case 0: // leer el coeficiente
            if (c == 'x') {
                
                aux[i] = '\0';
                state = 1;
                if (i == 0) coeficiente = 1;
                else coeficiente = atoi(aux);
                i = 0;
                
            } else if (c == '\n') {
                exp = 0;
                aux[i] = '\0';
                coeficiente = atoi(aux);
                i = 0;
                state = 0; 
                print_term(coeficiente*exp, exp - 1);
                printf("\n");
                //printf("%ix^%i\n", coeficiente*exp, exp-1);
                first = true;
            }
            else {
                aux[i++] = c;
            }
            break;
        case 1: // saber si hay exponente
            if (c == '+') {
                i = 0;
                state = 0;
                exp = 1; 
                print_term(coeficiente*exp, exp - 1);
                //printf("%ix^%i+", coeficiente*exp, exp-1);
            } else if(c == '^') {
                state = 2;
                i = 0;
            } else if (c == '\n') {
                i = 0;
                exp = 1;
                state = 0; 
                print_term(coeficiente*exp, exp - 1);
                printf("\n");
                //printf("%ix^%i\n", coeficiente*exp, exp-1);
                first = true;
            }
            
            break;
        case 2: // leer el exponente
            if (c == '+') {
                aux[i] = '\0';
                if (i == 0) exp = 1;
                else exp = atoi(aux);
                i = 0;
                state = 0;
                print_term(coeficiente*exp, exp - 1);
                //printf("%ix^%i+", coeficiente*exp, exp-1);
            } else if (c == '\n'){
                aux[i] = '\0';
                exp = atoi(aux);
                i = 0;
                state = 0; 
                print_term(coeficiente*exp, exp - 1);
                printf("\n");
                //printf("%ix^%i\n", coeficiente*exp, exp-1);
                first = true;
            } else {
                //std::cout << "guardando " << c << " en exp\n";
                aux[i++] = c; 
            }
            break;
        default:
            break;
        }
    }
    
    
    
    return 0;
}