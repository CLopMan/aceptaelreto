#include <iostream>
#include <string>
#include <algorithm>

int mem[81][81];

int __minTrim(char word[81], int start, int end) {
    if (mem[start][end] != -1) return mem[start][end];
    if (start == end) { mem[start][end] = 1;}
    else if (start > end) { mem[start][end] = 0;}
    else {
        int newst = start;
        int newend = end;
        char cst = word[start];
        char cnd = word[end];

        /* trim(cst) */
        while (word[newst] == cst) ++newst;
        /* trim(cnd) */
        while (word[newend] == cnd) --newend;

        if (cst == cnd) mem[start][end] = 1 +  __minTrim(word, newst, newend);
        else mem[start][end] = 1 + std::min(__minTrim(word, start, newend), __minTrim(word, newst, end));
    }
    return mem[start][end];
}

int minTrim(char word[81]) {
    int i, j;
    i = 0;
    j = std::char_traits<char>::length(word) - 1;
   
    return __minTrim(word, i, j);
}

int main () {
    char word[81];
    while (std::cin >> word) {
        for (int i = 0; i < 81; ++i) {
            for (int j = 0; j < 81; ++j)
                mem[i][j] = -1;
        }
        std::cout << minTrim(word) << "\n";
    }
    return 0;
}
