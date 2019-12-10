//
// Created by trykr on 16.11.2019.
//

#ifndef UNILABS_COMPLEX_H
#define UNILABS_COMPLEX_H

#include <iostream>
#include <cmath>
#pragma once

/**
 * Комплексное число
 */
typedef struct {
    float x;
    float y;
} Complex;

/**
 * Сложение
 */
Complex add(Complex a, Complex b)
{
    Complex result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

/**
 * Умножение
 */
Complex mul(Complex a, Complex b)
{
    Complex result;
    result.x = a.x * b.x - a.y * b.y;
    result.y = a.x * b.y + a.y * b.x;
    return result;
}

/**
 * Деление
 */
Complex div(Complex a, Complex b)
{
    Complex result;
    result.x = (a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y);
    result.y = (b.x * a.y - a.x *b.y) / (b.x * b.x + b.y * b.y);
    return result;
}

/**
 * Получение модуля
 */
float mod(Complex a)
{
    return static_cast<float>(sqrt(a.x * a.x + a.y * a.y));
}

/**
 * Получение аргумента
 */
float arg(Complex a)
{
    return static_cast<float>(atan(a.y / a.x));
}

/**
 * Получение сопряжённого
 */
Complex sop(Complex a)
{
    Complex result;
    result.x = a.x;
    result.y = -a.y;
    return result;
}

/**
 * Вывод в алгебраической форме
 */
void printAlg(Complex a)
{
    std :: cout << a.x << " + " << a.y << 'i';
}

/**
 * Вывод в тригонометрической форме
 */
void printTrig(Complex a)
{
    std :: cout << mod(a) << " * " << "( cos(" << arg(a) << ")  + i * sin( " << arg(a) << " )" << std :: endl;
}

/**
 * Вывод в показательной форме
 */
void printExp(Complex a)
{
    std :: cout << mod(a) << " * e^( i * " << arg(a) << " )" << std :: endl;
}
#endif //UNILABS_COMPLEX_H
