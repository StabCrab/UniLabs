//
// Created by trykr on 26.11.2019.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "ru");

    int n, m, res = 0;
    int k = 1;

    printf("Введите число: ");
    scanf("%d", &n);
    printf("Перевести в: ");
    scanf("%d", &m);

    int i = 0;
    printf("Ответ: ");
    while (i != -1)
    {
        int d = n / pow(m, i);

        if (d < 10)
            printf("%d", d);
        else
            printf("%c", 55 + d);

        n -= pow(m, i) * d;
        i--;
    }
    return 0;
}