#include <stdio.h>
#define MAX_SIZE 100

// Функція для знаходження кількості входжень максимального та мінімального елементів в матриці
void findOccurrences(int A[][MAX_SIZE], int n, int m) {
    int maxElement = A[0][0];  // Початкове значення максимального елементу
    int minElement = A[0][0];  // Початкове значення мінімального елементу
    int maxCount = 0;  // Лічильник кількості входжень максимального елементу
    int minCount = 0;  // Лічильник кількості входжень мінімального елементу

    // Знаходження максимального та мінімального елементів
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > maxElement) {
                maxElement = A[i][j];
            }
            if (A[i][j] < minElement) {
                minElement = A[i][j];
            }
        }
    }

    // Знаходження кількості входжень максимального та мінімального елементів
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == maxElement) {
                maxCount++;
            }
            if (A[i][j] == minElement) {
                minCount++;
            }
        }
    }

    // Виведення результатів
    printf("Максимальний елемент: %d\n", maxElement);
    printf("Кількість входжень максимального елементу: %d\n", maxCount);
    printf("Мінімальний елемент: %d\n", minElement);
    printf("Кількість входжень мінімального елементу: %d\n", minCount);
}

int main() {
    int n = 3;  // Кількість рядків
    int m = 4;  // Кількість стовпців
    int A[MAX_SIZE][MAX_SIZE];

    // Введення елементів матриці
    printf("Введіть елементи матриці A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Знаходження кількості входжень максимального та мінімального елементів
    findOccurrences(A, n, m);

    return 0;
}
