#include <bits/stdc++.h> 
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, *((bracket+i*n)+j), n, bracket, name);
    printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    cout << ")";
}

void matrixChainOrder(int p[], int n) {
    int m[n][n], bracket[n][n];
    memset(m, 0, sizeof(m));
    memset(bracket, 0, sizeof(bracket));

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n - 1, n, (int *)bracket, name);
    cout << endl;
    cout << "Minimum number of scalar multiplications: " << m[1][n - 1] << endl;
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n];
    cout << "Enter dimensions of matrices: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    matrixChainOrder(p, n);
    return 0;
}
