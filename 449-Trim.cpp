#include <iostream>
#include <string>
#include <algorithm>

/* divide y vencerás */
int __minTrim(char word[81], int start, int end) {
    if (start == end) { return 1;}
    if (start > end) { return 0;}
    int newst = start;
    int newend = end;
    char cst = word[start];
    char cnd = word[end];
    /* trim(cst) */
    while (word[newst] == cst) ++newst;
    /* trim(cnd) */
    while (word[newend] == cnd) --newend;
    if (cst == cnd) return 1 +  __minTrim(word, newst, newend);
    else return 1 + std::min(__minTrim(word, start, newend), __minTrim(word, newst, end));
}

int minTrim(char word[81]) {
    int i, j;
    i = 0;
    j = std::char_traits<char>::length(word) - 1;
   
    return __minTrim(word, i, j);
}

int main () {
    char word[81];
    while (std::cin >> word) std::cout << minTrim(word) << "\n"; 

    return 0;
}
