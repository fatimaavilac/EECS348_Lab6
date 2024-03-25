/*
 * File: main.cpp
 * Author: Fatima Avila Cobian
 * KUID: 2977231
 * Date: 3.22.24
 * Lab: Lab 6
 * Purpose: Program reads matrix data from input file and performs various matrix operations.
*/

#include <iostream>
#include <fstream>
#include <string>

void printMatrix(int (*arr)[3], int size) {

    /* Input: Reference to 2d matrix, size of matrix */
    /* Prints contents of 2d matrix. */

    for (int i = 0; i < size; i++) { // iterate through rows
        for (int j = 0; j < size; j++) { // iterate through columns
            printf("%d ", arr[i][j]);
        }
        std::cout << "\n";
    }
    
}

void addMatrix(int (*arr1)[3], int (*arr2)[3], int size) {

    /* Input: 2d matrix 1, 2d matrix 2, size of matrices */
    /* Adds the two matrices and prints the result. */

    int res[3][3]; // matrix to hold result

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = arr1[i][j] + arr2[i][j]; // res index = arr1 index + arr2 index
        }
    }
    
    std::cout << "\n";
    printMatrix(arr1, size); // print matrix 1
    std::cout << "  +\n";
    printMatrix(arr2, size); // print matrix 2
    std::cout << "  =\n";
    printMatrix(res, size); // print result matrix
}

void subMatrix(int (*arr1)[3], int (*arr2)[3], int size) {

    /* Input: 2d matrix 1, 2d matrix 2, size of matrices */
    /* Subtracts the first matrix from the second matrix, prints the result. */

    int res[3][3]; // matrix to hold result

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = arr2[i][j] - arr1[i][j]; // res index = arr1 index - arr2 index
        }
    }
    
    std::cout << "\n";
    printMatrix(arr2, size); // print matrix 1
    std::cout << "  -\n";
    printMatrix(arr1, size); // print matrix 2
    std::cout << "  =\n";
    printMatrix(res, size); // print result matrix
}

void multMatrix(int (*arr1)[3], int (*arr2)[3], int size) {

    /* Input: 2d matrix 1, 2d matrix 2, size of matrices */
    /* Multiplies the two matrices and prints the result. */

    int res[3][3]; // matrix to hold result

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    std::cout << "\n";
    printMatrix(arr1, size); // print matrix 1
    std::cout << "  *\n";
    printMatrix(arr2, size); // print matrix 2
    std::cout << "  =\n";
    printMatrix(res, size); // print result matrix

}

void update(int (&arr)[3][3], int size) {

    /* Input: Reference to 2d matrix, size of matrix */
    /* Prompts user for row, column, and new value.
       Updates the matrix with given data. */
    
    int row, col; // row and column to be updated
    int x = 0; // new value

    std::cout << "\nEnter row: "; // prompt user for row
    scanf("%d", (&row));
    std::cout << "Enter column: "; // prompt user for column
    scanf("%d", (&col));

    // verify user input
    if (row >= 0 && row < size && col >= 0 && col < size) {

        std::cout << "\nEnter new value: "; // prompt user for new value
        scanf("%d", (&x));
        arr[row][col] = x; // update index
        std::cout << "\n";
        printMatrix(arr, size); // print updated matrix

    } else { // if input invalid
        // print error mssg
        std::cout << "<Error> Invalid row or column\n";
    }
}

void findMax(int (*arr)[3], int size) {

    /* Input: 2d matrix, size of matrix */
    /* Finds the max value in given matrix, prints result. */
    
    int max = arr[0][0]; // maximum value

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // if value in matrix is greater than max
            if (arr[i][j] > max) { 
                max = arr[i][j]; // update max
            }
        }
    }

    printf("\nMatrix 1 Max: %d\n", max);

}

void transpose(int (&arr)[3][3], int size) {

    /* Input: Reference to 2d matrix, size of matrix */
    /* Transposes given matrix, prints result. */
    
    int res[3][3]; // matrix to hold result

    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = arr[j][i]; // transposed value
        }
    }

    std::cout << "\n";
    printMatrix(res, size); // print result matrix
}

int main(int argc, char* argv[]) {

    // check for valid arguments
    if (argc != 2) { 
        // if invalid, print error message
        std::cout << "<Error> Must provide input file.\n";
        std::cout << "Format: ./prog <filename>\n";
        return 0; // exit
    }

    std::ifstream infile;
    infile.open(argv[1]);

    // try to open input file
    if (infile.is_open()) {

        int m1[3][3]; // matrix 1
        int m2[3][3]; // matrix 2
        int r = 0; // line count
        int n; // matrix size

        infile >> n; // read matrix size from file

        std::cout << "\nMATRIX CALCULATOR\n";
        std::cout << "\nReading from file...\n";

        // read input from file
        for (int i = 0; i < n*2; i++) {
            for (int j = 0; j < n; j++) {
                // if within lines 0 - n
                if (i < n) {
                    infile >> m1[i][j]; // store in matrix 1
                } else {
                    infile >> m2[i-n][j]; // store in matrix 2
                }
            }
            r++; // increment line count
        }

        // if file contains invalid amount of data
        if (r > n*2) {
            // print error message
            std::cout << "<Error> File contains invalid matrices.\n";
            return 0; // exit
        }

        while(1) {

            int choice; // user menu choice
            std::cout << "\n1) Print a Matrix\n";
            std::cout << "2) Add Matrices\n";
            std::cout << "3) Subtract Matrices\n";
            std::cout << "4) Multiply matrices\n";
            std::cout << "5) Update Matrix 1\n";
            std::cout << "6) Find Matrix 1 Max\n";
            std::cout << "7) Transpose Matrix 1\n";
            std::cout << "8) Quit\n";
            std::cout << "Choice: ";
            scanf("%d", &choice);

            // switch case table for user's menu choice
            switch (choice) {

                case 1:
                    // Print Menu
                    std::cout << "\n1) Print Matrix 1\n";
                    std::cout << "2) Print Matrix 2\n";
                    std::cout << "Choice: ";
                    scanf("%d", &choice);

                    if (choice == 1) {
                        std::cout << "\nMatrix 1:\n";
                        printMatrix(m1, n);
                    } else if (choice == 2) {
                        std::cout << "\nMatrix 2:\n";
                        printMatrix(m2, n);
                    } else {
                        // check for invalid input
                        std::cout << "\n<Error> Invalid input.\n";
                    }
                    
                    break;
                case 2:
                    // Add Matrices
                    addMatrix(m1, m2, n);
                    break;
                case 3:
                    // Subtract Matrices
                    subMatrix(m1, m2, n);
                    break;
                case 4:
                    // Multiply Matrices
                    multMatrix(m1, m2, n);
                    break;
                case 5:
                    // Update Matrices
                    update(m1, n);
                    break;
                case 6:
                    // Find Matrix 1 Max
                    findMax(m1, n);
                    break;
                case 7:
                    // Transpose Matrix 1
                    transpose(m1, n);
                    break;
                case 8:
                    // Quit
                    std::cout << "Goodbye...\n\n";
                    return 0;
                default:
                    // check for invalid input
                    std::cout << "\n<Error> Invalid option.\n";

            }

        }

    } else { 
        // if file cannot open, print error message
        std::cout << "<Error> File could not be opened.\n";
    }

    infile.close();

    return 0;
    
}