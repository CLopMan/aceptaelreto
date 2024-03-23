#include <stdio.h> 
#include <string.h>

#define MAXSIZE 10002

int main () {
    char buffer[MAXSIZE];
    char stack[MAXSIZE];
    while (NULL != fgets(buffer, MAXSIZE, stdin)) {
        int indice = 0; 
        int size = strlen(buffer);
        int correcto = 1;
        int i;
        for (i = 0; i < size; ++i) {
            if (buffer[i] == '(' || buffer[i] == '[' || buffer[i] == '{') {
                stack[indice++] = buffer[i];
            } else {
                switch (buffer[i])
                {
                case ')':
                    if (indice == 0 || stack[indice - 1] != '(') {
                        correcto = 0;
                    } else {
                        --indice;
                    }
                    break;

                case ']':
                    if (indice == 0 || stack[indice - 1] != '[') {
                        correcto = 0;
                    } else {
                        --indice;
                    }
                    break;

                case '}':
                    if (indice == 0 || stack[indice - 1] != '{') {
                        correcto = 0;
                    } else {
                        --indice;
                    }
                    break;
                
                default:
                    break;
                }
                if (!correcto) {
                    break;
                }
            }
            
        }
        if (indice == 0 && correcto) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }
    return 0;
}