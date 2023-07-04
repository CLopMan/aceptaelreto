/*https://aceptaelreto.com/problem/statement.php?id=140&cat=17*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0; 
    char c;
    int first = 1;
    c = getc(stdin);
    while(c != '-') {
        if (c == '\n') {
            printf(" = %i\n", sum);
            first = 1;
            sum = 0;
        } else {
            if (!first) {
                printf(" + ");
            }
            printf("%c", c);
            sum += c - '0';
            first = 0;
        } 
        c = getc(stdin);
    }
    return 0;
}