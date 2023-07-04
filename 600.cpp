#include <stdio.h>
#include <iostream>

#define MAX_SIZE 300

int matrix[MAX_SIZE][MAX_SIZE];

int min_row(int matrix[MAX_SIZE][MAX_SIZE], int row, int len, int* pos) {
    // given an array returns de minimum value of a specified row and saves its position in 'pos'
    int min = matrix[row][0];
    *pos = 0;
    for (int i = 1; i < len; ++i) {

        if (matrix[row][i] < min){
            min = matrix[row][i];
            *pos = i;
        }
    }
    return min;
}

int max_row(int matrix[MAX_SIZE][MAX_SIZE], int row, int len, int* pos) {
    // given a matrix returns de maximun value of a specified row and saves its position in 'pos'
    int max = matrix[row][0];
    *pos = 0;
    for (int i = 1; i < len; ++i) {
        if (matrix[row][i] > max){
            max = matrix[row][i];
            *pos = i;
        }
    }
    return max;
}

int min_column(int matrix[MAX_SIZE][MAX_SIZE], int column, int len, int* pos) {
    int min = matrix[0][column];
    *pos = 0;
    for (int i = 1; i < len; ++i) {
        if (matrix[i][column] < min){
            min = matrix[i][column];
            *pos = i;
        }
    }
    return min;
}

int max_column(int matrix[MAX_SIZE][MAX_SIZE], int column, int len, int* pos) {
    int max = matrix[0][column];
    *pos = 0;
    for (int i = 1; i < len; ++i) {
        if (matrix[i][column] > max){
            max = matrix[i][column];
            *pos = i;
        }
    }
    return max;
}

int main() {
    int columns = -1;
    int rows = -1;
    std::cin >> rows >> columns;
    while (rows != 0) {
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cin >> matrix[i][j];
            }
        }

        int haberlos_hailos = 0;

        for (int i = 0; i < rows; ++i) {
            int column_min_row;
            int min_of_row = min_row(matrix, i, columns, &column_min_row);
            int max_of_column = max_column(matrix, column_min_row, rows, &column_min_row);

            if (min_of_row == max_of_column) {
                printf("SI\n");
                haberlos_hailos = 1;
                break;
            }
            int column_max_row;
            int max_of_row = max_row(matrix, i, columns, &column_max_row);
            int min_of_column = min_column(matrix, column_max_row, rows, &column_max_row);

            if (max_of_row == min_of_column) {
                printf("SI\n");
                haberlos_hailos = 1;
                break;
            }
        }
        if (!haberlos_hailos) {
            printf("NO\n");
        }
        std::cin >> rows >> columns;
    }
    
    return 0;
}