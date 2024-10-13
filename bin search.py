import random
k = 0

mas = []
for i in range(1,101):
    mas.append(i)
mas.sort()
print(mas)

number = random.randint(1,101)
print("Заданное число: ", number)

left = 0
right = len(mas) - 1
middle =(left + right) // 2

while mas[middle] != number:
    if mas[middle] < number:
        left = middle + 1
    else:
        right = middle - 1
    middle = (left + right) // 2
    k += 1

if number == mas[middle]:
    print("Найденное число: ", number)
    print("Кол-во шагов: ", k)
