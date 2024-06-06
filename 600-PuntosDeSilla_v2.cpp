#include <stdio.h>
#include <iostream>

int matrix[300][300];

int max_row(int x, int matrix[300][300], int row, int column) {
    int max = matrix[x][0];
    for (int i = 0; i < column; ++i) {
        if (matrix[x][i] > max) {
            max = matrix[x][i];
        }
    }
    return max;
}

int max_column(int x, int matrix[300][300], int row, int column) {
    int max = matrix[0][x];
    for (int i = 0; i < row; ++i) {
        if (matrix[i][x] > max) {
            max = matrix[i][x];
        }
    }
    return max;
}

int min_row(int x, int matrix[300][300], int row, int column) {
    int min = matrix[x][0];
    for (int i = 0; i < column; ++i) {
        if (matrix[x][i] < min) {
            min = matrix[x][i];
        }
    }
    return min;
}

int min_column(int x, int matrix[300][300], int row, int column) {
    int min = matrix[0][x];
    for (int i = 0; i < row; ++i) {
        if (matrix[i][x] < min) {
            min = matrix[i][x];
        }
    }
    return min;
}

bool punto_de_silla(int i, int j, int matrix[300][300], int row, int column) {
    int element = matrix[i][j];
    if (element == max_row(i, matrix, row, column) && element == min_column(j, matrix, row, column)) {
        return true;
    }
    if (element == min_row(i, matrix, row, column) && element == max_column(j, matrix, row, column)) {
        return true;
    }
    return false;
}

int main() {
    int rows;
    int columns;
    std::cin >> rows >> columns;
    while (rows != 0) {
        bool haberlos_hailos = false;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (punto_de_silla(i, j, matrix, rows, columns)) {
                    haberlos_hailos = true;
                    break;
                }
            }
        }
        if (haberlos_hailos) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    std::cin >> rows >> columns;
    }
}
