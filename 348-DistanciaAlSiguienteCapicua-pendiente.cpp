#include <iostream>
#include <stdlib.h>
#include <string>

int isPalindrome(std::string n) {
    int i = 0;
    int j = n.length() - 1; 
    while (i < j) {
        if (n[i] != n[j]) {
            return 0;
        }
        ++i;
        --j;
    }
    return 1;
}

int nextpalindrome(std::string n, int len) {
    int num = stoi(n);
    int mid = len/2 + 1;
    return 0; 

    
}

int main() {
    int casos; 
    std::cin >> casos;
    for (int i = 0; i < casos; ++i) {
        std::string n;
        std::cin >> n;
        std::cout << isPalindrome(n);
        //printf("%i", nextpalindrome(n, n.length()) - atoi(n));
    }
    return 0;

}
