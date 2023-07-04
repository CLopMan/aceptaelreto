#include <iostream>
#include <stdlib.h>

int nextpalindrome(std::str n, int len) {
    bool par = !len%2;
    int eje = len/2;
    int i, j = eje;
    --i; 
    if(!par) {
        ++j;
    }
    
    while (j < len && i > 0) {

    }

}

int main() {
    int casos; 
    scanf("%i", &casos);
    for (int i = 0; i < casos; ++i) {
        std::string n;
        std::cin >> n;
        printf("%i", atoi(n) - nextpalindrome(n, strlen(n)));
    }
    return 0;

}