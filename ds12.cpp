#include <iostream>
using namespace std;

void printSquare(int sq[][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sq[i][j] << "\t";
        cout << endl;
    }
}

bool verifyMagic(int sq[][50], int n) {
    int magicSum = 0;
    for (int j = 0; j < n; j++) magicSum += sq[0][j];

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += sq[i][j];
        if (sum != magicSum) return false;
    }

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += sq[i][j];
        if (sum != magicSum) return false;
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += sq[i][i];
        d2 += sq[i][n - i - 1];
    }
    return (d1 == magicSum && d2 == magicSum);
}

void oddMagic(int n, int sq[][50]) {
    int num = 1, i = 0, j = n / 2;
    while (num <= n * n) {
        sq[i][j] = num;
        num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (sq[newi][newj] != 0)
            i = (i + 1) % n;
        else {
            i = newi;
            j = newj;
        }
    }
}

void doublyEvenMagic(int n, int sq[][50]) {
    int val = 1;
    int total = n * n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sq[i][j] = val++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                sq[i][j] = total - sq[i][j] + 1;
}

int main() {
    int n;
    int sq[50][50] = {0};

    cout << "Enter order of magic square: ";
    cin >> n;

    if (n % 2 == 1)
        oddMagic(n, sq);
    else if (n % 4 == 0)
        doublyEvenMagic(n, sq);
    else {
        cout << "Singly even magic square not supported.\n";
        return 0;
    }

    printSquare(sq, n);

    if (verifyMagic(sq, n))
        cout << "Valid Magic Square\n";
    else
        cout << "Invalid Magic Square\n";

    return 0;
}

