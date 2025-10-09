#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int table[n][n];

    // Read table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }

    // Compute row sums
    int rowSum[n];
    for (int i = 0; i < n; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < n; j++) {
            rowSum[i] += table[i][j];
        }
    }

    // Find correct row sum (appears at least N-1 times)
    int correctRowSum, wrongRowSum, wrongRow = -1;
    if (rowSum[0] == rowSum[1] || rowSum[0] == rowSum[2]) {
        correctRowSum = rowSum[0];
    } else {
        correctRowSum = rowSum[1];
    }
    for (int i = 0; i < n; i++) {
        if (rowSum[i] != correctRowSum) {
            wrongRowSum = rowSum[i];
            wrongRow = i;
            break;
        }
    }

    // Compute column sums
    int colSum[30];
    for (int j = 0; j < n; j++) {
        colSum[j] = 0;
        for (int i = 0; i < n; i++) {
            colSum[j] += table[i][j];
        }
    }

    // Find correct column sum (appears at least N-1 times)
    int correctColSum, wrongColSum, wrongCol = -1;
    if (colSum[0] == colSum[1] || colSum[0] == colSum[2]) {
        correctColSum = colSum[0];
    } else {
        correctColSum = colSum[1];
    }
    for (int j = 0; j < n; j++) {
        if (colSum[j] != correctColSum) {
            wrongColSum = colSum[j];
            wrongCol = j;
            break;
        }
    }

    // Fix the wrong cell
    int diff = correctRowSum - wrongRowSum;
    int correctedValue = table[wrongRow][wrongCol] + diff;

    cout << correctedValue << endl;
}