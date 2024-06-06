#include <stdio.h> 

int euclides_gcd(int long long n1, int long long n2){
    /*algoritmo de euclides para calcular el máximo común divisor */
    if (n2>n1){
        int long long aux = n1;
        n1 = n2;
        n2 = aux;
    }
    while (n2 != 0){
        
        int long long aux1 = n2;
        n2 = n1%n2;
        n1 = aux1;
        }
        return n1;
        
}
int lcm(int long long n1,int long long n2){
    /*cálculo del mínimo común múltiplo*/
    return (n1*n2)/euclides_gcd(n1, n2);
}

int main(){
    int long long personas;

    scanf("%lld", &personas);
    while (personas != 0){
        int long long mcm = 1;
        int long long sum = 0;
        int cont = 0;
        int long long numeradores[10000];
        int long long denominadores[10000];

        while (cont < personas){

            scanf("%lld/%lld", &numeradores[cont], &denominadores[cont]); // entradas de las fracciones en dos arrays
            mcm = lcm(denominadores[cont],mcm); // cálculo del mcm
            ++cont;
        }
        cont = 0;

        while (cont < personas){
            sum = sum + numeradores[cont]*(mcm/denominadores[cont]);
            ++cont;
        }
        printf("%lld\n", mcm - sum);
        scanf("%lld", &personas);
    }
}
