#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int matrix[50][50];
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];

    int sparse[50][3]; // Each row: [row, col, value]
    int count = 0;

    // Store non-zero elements in sparse array
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
                count++;
            }

    // Display sparse representation
    cout << "\nSparse Matrix Representation (row, col, value):\n";
    for(int i = 0; i < count; i++)
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;

    // Transpose sparse matrix
    int transpose[50][3];
    for(int i = 0; i < count; i++) {
        transpose[i][0] = sparse[i][1]; // row <- col
        transpose[i][1] = sparse[i][0]; // col <- row
        transpose[i][2] = sparse[i][2]; // value stays same
    }

    // Display transpose
    cout << "\nTranspose of Sparse Matrix:\n";
    for(int i = 0; i < count; i++)
        cout << transpose[i][0] << "\t" << transpose[i][1] << "\t" << transpose[i][2] << endl;

    return 0;
}

