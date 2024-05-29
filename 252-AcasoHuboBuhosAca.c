#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256
/* detect palindromes */
/* first version: preprocess the string to remove spaces and \n. Then checks palindrome to len/2
 * second version: just one loop, ignoring spaces and \n
 */

int preprocess(char input[SIZE]);

int isPalindrome(char phrase[SIZE]) {
    int lenght = preprocess(phrase);
    int i = 0; 
    for (i = 0; i < lenght/2 + 1; ++i) {
        if (phrase[i] != phrase[lenght - i - 1]) {
            return 0;
        }
    }

    return 1;
}

/* returns the lenght of input after erasing spaces and end of line*/
int preprocess(char input[SIZE]) {
    int len = 0; 
    int i = 0;
    int limit = strlen(input);
    for (i = 0; i < limit; ++i)  {
        char c = toupper(input[i]);
        if (c != ' ' && c != '\n') {        
            input[len++] = c;
        }
        
    }
    input[len] = '\0';
    return len;
}

int isPalindromeV2(char phrase[SIZE]) {
    int lenght = strlen(phrase);
    if (phrase[lenght - 1] == '\n') --lenght;

    int i = 0, j = lenght - 1;
    while (i < j) {
        char ci = toupper(phrase[i++]);
        while (ci == ' ') ci = toupper(phrase[i++]);
        char cj = toupper(phrase[j--]); 
        while (cj == ' ') cj = toupper(phrase[j--]);

        if (ci != cj) return 0;
    }
    return 1;
}

int main() {
    char stopCond[] = "XXX\n"; 
    char input[SIZE];
    fgets(input, SIZE, stdin);
    while (strcmp(input, stopCond)) {
        if (isPalindromeV2(input) == 1) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
        fgets(input, SIZE, stdin);
    }

    return 0;
}
