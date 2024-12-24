def gauss(A, b):
  n = len(b)
  matrix = [row + [b[i]] for i, row in enumerate(A)]

  # Прямой ход
  for i in range(n):
    pivot = matrix[i][i]
    if pivot == 0:
      return None
    matrix[i] = [x / pivot for x in matrix[i]]

    for j in range(i + 1, n):
      factor = matrix[j][i]
      matrix[j] = [x - factor * y for x, y in zip(matrix[j], matrix[i])]

  # Обратный ход
  x = [0] * n
  for i in range(n - 1, -1, -1):
    x[i] = matrix[i][n]
    for j in range(i + 1, n):
      x[i] -= matrix[i][j] * x[j]
  return x





A = [[1, 2, 3], [1, -1, 1], [1, 3, -1]]
b = [2, 0, -2]

solution = gauss(A, b)
if solution is not None:
  print("Решение СЛАУ:", solution)
else:
  print("Ошибка")
