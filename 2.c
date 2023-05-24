#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3 // Розмірність квадратної матриці

// Функція для генерації симетричної матриці з допомогою генератора псевдовипадкових чисел
void generateMatrix(int A[][SIZE])
{
    srand(time(NULL)); // Ініціалізуємо генератор псевдовипадкових чисел залежно від поточного часу

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++) // Генеруємо тільки верхню частину матриці
        {
            int number = rand() % 201 - 100; // Генеруємо випадкове число від -100 до 100
            A[i][j] = number;
            A[j][i] = number; // Заповнюємо відповідний елемент симетрично
        }
    }
}

// Функція для виведення матриці на екран
void printMatrix(int A[][SIZE])
{
    printf("Матриця:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int number = A[i][j];
            if (number < 0)
            {
                printf("\x1B[35m%4d\x1B[0m ", number);
            }
            else if (number > 0)
            {
                printf("\x1B[34m%4d\x1B[0m ", number);
            }
            else
            {
                printf("%4d ", number);
            }
        }
        printf("\n");
    }
}

// Функція для перевірки, чи є матриця симетричною відносно головної діагоналі
int isMatrixSymmetric(int A[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (A[i][j] != A[j][i])
            {
                return 0; // Матриця не є симетричною
            }
        }
    }
    return 1; // Матриця є симетричною
}

int main()
{
    int A[SIZE][SIZE];

    generateMatrix(A); // Генеруємо симетричну матрицю

    printMatrix(A); // Виводимо матрицю на екран

    if (isMatrixSymmetric(A))
    {
        printf("Матриця є симетричною відносно головної діагоналі.\n");
    }
    else
    {
        printf("Матриця не є симетричною відносно головної діагоналі.\n");
    }

    return 0;
}

