#include <iostream>
#include <string>
#include <algorithm>

int mem[81][81];

int minTrim(std::string &word) {
    int len = word.length() - 1;
    mem[0][0] = 1;
    mem[1][0] = 0;
    for (int i = len; i >= 0; --i) {
        mem[i][i] = 1;
        mem[i][i-1] = 0;
        for (int j = i + 1; j <= len; ++j) {
           if (word[i] == word[j]) mem[i][j] = 1 + mem[i+1][j-1];
           else {
                mem[i][j] = 1 + std::min(mem[i + 1][j], mem[i][j-1]);
           }
        }

    }
    /*for (int i = 0; i <= len; ++i){
        for (int j = 0; j <= len; ++j) {
            std::cout << " " << mem[i][j] << " ";
        }
        std::cout << "\n";
    } */
    return mem[0][len];
}

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    std::string word;
    while (std::cin >> word) {
        word.erase(std::unique(word.begin(), word.end()), word.end()); // remove consecutive duplicates
        std::cout << minTrim(word) << "\n";
    }
    return 0;
}
