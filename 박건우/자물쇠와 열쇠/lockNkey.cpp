#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix, int matrixSize) {
    vector<vector<int>> temp(matrixSize, vector<int>(matrixSize, 0));

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            temp[i][j] = matrix[matrixSize - j - 1][i];
        }
    }

    matrix = temp;
}


bool unlockable(vector<vector<int>> key, vector<vector<int>> matrix, int keySize, int matrixSize) {
    vector<vector<int>> temp(matrixSize, vector<int>(matrixSize));

    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < matrixSize - keySize; i++) {
            for (int j = 0; j < matrixSize - keySize; j++) {

                for (int k = i; k < i + keySize; k++) {
                    for (int l = j; l < j + keySize; l++) {
                        matrix[k][l] += key[k - i][l - j];
                    }
                }

                for (int k = keySize - 1; k <= matrixSize - keySize; k++) {
                    for (int l = keySize - 1; l <= matrixSize - keySize; l++) {
                        if (matrix[k][l] != 1) { return false; }
                    }
                }

                temp = matrix;
            }
        }
        rotate(matrix, matrixSize);
    }

    return true;
}


bool solution(const vector<vector<int>> lock, const vector<vector<int>> key) {
    int lockSize = (int)lock.size();
    int keySize = (int)key.size();
    int matrixSize = lockSize + (keySize - 1) * 2;

    vector<vector<int>> matrix(matrixSize, vector<int>(matrixSize, 0));

    for (int i = keySize - 1; i <= matrixSize - keySize; i++) {
        for (int j = keySize - 1; j <= matrixSize - keySize; j++) {
            matrix[i][j] = lock[i - keySize + 1][j - keySize + 1];
        }
    }

    if(unlockable(key, lock, keySize, lockSize)) {
        return true;
    }

    return false;
}

int main() {
    vector<vector<int>> lock = {{1, 1, 1},{1,1,0},{1,0,1}};
    vector<vector<int>> key = {{0,0,0}, {1,0,0}, {0,1,1}};
    if(solution(lock, key)) {
        cout << "Ting!";
    }
}