#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double value : row) {
            cout << setw(10) << setprecision(4) << value << " ";
        }
        cout << endl;
    }
}

vector<double> gaussianElimination(vector<vector<double>> matrix) {
    int n = matrix.size();

    // Прямой ход
    for (int i = 0; i < n; i++) {
        double maxElement = fabs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > maxElement) {
                maxElement = fabs(matrix[k][i]);
                maxRow = k;
            }
        }

        swap(matrix[i], matrix[maxRow]);

        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    vector<double> result(n);
    for (int i = n - 1; i >= 0; i--) {
        result[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix[k][n] -= matrix[k][i] * result[i];
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;

    cout << "Введите размерность матрицы: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Введите элементы расширенной матрицы (коэффициенты и свободные члены):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    vector<double> result = gaussianElimination(matrix);

    cout << "Решение системы:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << setprecision(6) << result[i] << endl;
    }

    return 0;
}
