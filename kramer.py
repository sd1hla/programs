import numpy as np


def cramer_method(coeff_matrix, const_terms):

    det_main = np.linalg.det(coeff_matrix)

    if det_main == 0:
        raise ValueError("Система не имеет единственного решения (определитель равен нулю).")

    n = coeff_matrix.shape[0]
    solutions = []

    for i in range(n):
        # Копируем исходную матрицу
        modified_matrix = coeff_matrix.copy()

        # Заменяем i-й столбец вектором свободных членов
        modified_matrix[:, i] = const_terms

        # Вычисляем определитель модифицированной матрицы
        det_modified = np.linalg.det(modified_matrix)

        # Вычисляем значение переменной
        solutions.append(det_modified / det_main)

    return solutions


if __name__ == "__main__":
    # Ввод размерности матрицы
    n = int(input("Введите размерность (количество уравнений): "))

    print("Введите коэффициенты матрицы построчно и через пробел:")
    coeff_matrix = []
    for i in range(n):
        row = list(map(float, input(f"Строка {i + 1}: ").split()))
        if len(row) != n:
            raise ValueError("Коэффициентов в строке должно быть столько же, сколько уравнений!")
        coeff_matrix.append(row)

    coeff_matrix = np.array(coeff_matrix, dtype=float)

    print("Введите вектор свободных членов (через пробел):")
    const_terms = np.array(list(map(float, input().split())), dtype=float)
    if len(const_terms) != n:
        raise ValueError("Размер вектора свободных членов должен совпадать с размерностью системы!")

    # Решение системы
    try:
        result = cramer_method(coeff_matrix, const_terms)
        print("Решение системы:")
        for i, x in enumerate(result, start=1):
            print(f"x{i} = {x:.6f}")
    except ValueError as e:
        print(e)