#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <locale.h>

#define MAX 1000
#define MIN_VAL -50 
#define MAX_VAL 50  

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    int a[MAX];

    srand((unsigned)time(NULL));

    printf("Введите n: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Некорректное n (должно быть от 1 до %d)\n", MAX);
        return 1;
    }

    
    printf(" массив:\n");
    for (int i = 0; i < n; i++) {
        a[i] = MIN_VAL + rand() % (MAX_VAL - MIN_VAL + 1);
        printf("a[%d] = %d\n", i, a[i]);
    }

    int sum = 0;
    int count = 0;
    for (int i = 2; i < n; i += 2) {
        sum += a[i];
        count++;
    }

    if (count == 0)
        printf("Элементов с четными индексами  нет\n");
    else
        printf("Среднее значение элементов: %.2f\n", (double)sum / count);

    return 0;
}

