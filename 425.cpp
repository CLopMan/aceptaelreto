#include <stdio.h>
#include <iostream>

#define MAX_SIZE 101

int matrix[MAX_SIZE][MAX_SIZE];

/*int addToBePalindrome(std::string word, int i, int j) {
    if (matrix[i][j] != -1) {
        return matrix[i][j];
    }
    // reursión
    if (i >= j) {
        //std::cout << "base\n";
        return 0;
    } else if (word[i] == word[j]) {
        if (matrix[i + 1][j - 1] == -1) {
            matrix[i + 1][j - 1] =  addToBePalindrome(word, i + 1, j - 1);
        }
        return matrix[i + 1][j - 1];
    } else {
        matrix[i + 1][j] = addToBePalindrome(word, i + 1, j);
        matrix[i][j - 1] = addToBePalindrome(word, i, j - 1);
        return std::min(matrix[i + 1][j], matrix[i][j - 1]) + 1;
    }
}*/

/*void print_matrix(int matrix[101][101], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

}*/

int addToBePalindrome_it(std::string word, int size) {
    for (int j = 0; j < size; ++j) {
        for (int i = size - 1; i >= 0; --i) {
            if (i >= j) {
                matrix[i][j] = 0;
            } else if (word[i] == word[j]) {
                matrix[i][j] = matrix[i + 1][j - 1];
            } else {
                matrix[i][j] = std::min(matrix[i + 1][j], matrix[i][j - 1]) + 1;
            }

        }

    }
}



int main() {
    std::string input;
    while (std::cin >> input) {
        int size = input.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = -1;
            }
        }
        addToBePalindrome_it(input, size);
        //std::cout << addToBePalindrome(input, 0, size - 1) << "\n"; //recursiva
        std::cout << matrix[0][size - 1] << "\n";
        
    }
}