#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления определителя матрицы 2x2
double determinant2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}

// Функция для вычисления определителя матрицы 3x3
double determinant3x3(vector<vector<double>> matrix) {
    return matrix[0][0] * determinant2x2(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]) -
        matrix[0][1] * determinant2x2(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]) +
        matrix[0][2] * determinant2x2(matrix[1][0], matrix[1][1], matrix[2][0], matrix[2][1]);
}

// Функция замены столбца в матрице
vector<vector<double>> replaceColumn(vector<vector<double>> matrix, vector<double> column, int colIndex) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][colIndex] = column[i];
    }
    return matrix;
}

int main() {
    setlocale("LC_ALL", "Rus")

    // Матрица коэффициентов
    vector<vector<double>> A = {
        {2, -1, 3},
        {1, 1, -2},
        {3, 2, -1}
    };

    // Вектор правой части
    vector<double> b = { 5, -3, 4 };

    // Вычисляем главный определитель
    double detA = determinant3x3(A);

    if (detA == 0) {
        cout << "Система не имеет единственного решения (определитель равен 0)." << endl;
        return 0;
    }

    // Вычисляем определители для замены столбцов
    double detX = determinant3x3(replaceColumn(A, b, 0));
    double detY = determinant3x3(replaceColumn(A, b, 1));
    double detZ = determinant3x3(replaceColumn(A, b, 2));

    // Решение системы
    double x = detX / detA;
    double y = detY / detA;
    double z = detZ / detA;

    // Вывод решения
    cout << "Решение системы:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}