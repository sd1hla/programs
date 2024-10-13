#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int k = 0;

    int mas[100];
    for (int i = 0; i < 100; ++i) {
        mas[i] = i + 1;
    }
    for (const auto& num : mas) {
        cout << num << " ";
    }
    cout << endl;

    srand(time(0));
    int number = rand() % 101 + 1;
    cout << "Zadannoe chislo: " << number << endl;

    int left = 0;
    int right = 99;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (mas[middle] == number) {
            cout << "Naidennoe chislo: " << number << endl;
            cout << "Kol-vo shagov: " << k << endl;
            break;
        }
        else if (mas[middle] < number) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
        k += 1;
    }

    return 0;
}