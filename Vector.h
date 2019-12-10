//
// Created by trykr on 13.11.2019.
//

#ifndef UNILABS_VECTOR_H
#define UNILABS_VECTOR_H

#include <iostream>
using namespace std;
#pragma once

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

/**
 * Динамически создаёт структуру вектора,
 * инициализирует нулями и возвращает указатель
 * на неё.
 */
Vector *createVector(size_t size)
{
    auto* vector = new Vector;
    auto* data = new int[size];
    vector->data = data;
    vector->size = size;
    vector->capacity = size;
}

/**
 * Удаляет данные внутри вектора
 * и сам вектор.
 *
 * @param v Удаляемый вектор
 */
void deleteVector(Vector *v)
{
    delete[] v->data;
    delete[] v;
}

/**
 * Установить объём (capacity) вектора в значение большее или равное newCap.
 * Если `newCap <= capacity`, ничего не делает.
 * @param v Вектор
 * @param newCap Новый объём
 */
void reserve(Vector *v, size_t newCap)
{
    if (newCap > v->size)
    {
        Vector* new_vector = createVector(newCap);
        memcpy(&new_vector->data, &v->data, v->size);
        v->data = new_vector->data;
        delete new_vector;
        v->capacity = newCap;
    }

}


/**
 * Динамически создаёт новый вектор ---
 * полную копию указанного.
 *
 * @param v Копируемый вектор
 */
Vector *copyVector(Vector *v)
{
    auto* vector = new Vector;
    vector->data = v->data;
    vector->capacity = v->capacity;
    vector->size = v->size;
    return vector;
}

/**
 * Меняет местами содержимое векторов
 * @param lh Первый вектор
 * @param rh Второй вектор
 */
void swapVector(Vector *lh, Vector *rh)
{
    auto* mid = copyVector(lh);
    lh->data = rh->data;
    lh->capacity = rh->capacity;
    lh->size = rh->size;
    rh->data = mid->data;
    rh->capacity = mid->capacity;
    rh->size = mid->size;
    delete[] mid;
}

/**
 * Получить значение элемента по заданной позиции
 * @param v Вектор
 * @param index Позиция
 */
int getValue(Vector *vector, size_t index)
{
    return vector->data[index];
}

/**
 * Получить размер вектора
 * (количество добавленных элементов)
 * @param v Вектор
 */
size_t getSize(Vector *v)
{
    return v->size;
}

/**
 * Получить вместимость вектора
 * (максимальное количество элементов, которое можно хранить в
 *  выделенном на данный момент блоке памяти)
 * @param v Вектор
 */
size_t getCapacity(Vector *v)
{
    return v->capacity;
}

/**
 * Добавить значение в конец вектора.
 * Если выделенной памяти не достаточно
 * для добавления элемента,
 * выделить новый массив большего размера
 * и скопировать в него старые значения
 * @param v Вектор
 * @param value Значение
 */
void append(Vector *v, int value)
{
    if (v->size == v->capacity)
    {
        reserve(v, v->capacity + 1);
        v->data[v->size ] = value;
    }
    else
    {
        v->data[v->size] = value;
    }
    v->size++;
}

/**
 * Добавить несколько значений из массива в конец вектора.
 * Если выделенной памяти недостаточно,
 * см. void append(int)
 * @param v Вектор
 * @param array Массив
 * @param count Количество элементов
 */
void append(Vector *v, int *array, size_t count)
{
    if (count > v->capacity - v->size)
    {
        if (count > v->capacity - v->size)
        {
            reserve(v, v->capacity + count);
            for (int i = 0; i < count; i++)
            {
                v->data[i + v->size] = array[i];
            }
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                v->data[i + v->size] = array[i];
            }
        }
        v->size += count;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            v->data[v->size + i] = array[i];
        }
    }
}

/**
 * Вставить значение на заданную позицию.
 * и сдвинуть элементы справа.
 * Если выделенной памяти недостаточно,
 * см. void append(int)
 * @param v Вектор
 * @param index Позиция вставки
 * @param value Значение
 */
void insert(Vector *v, size_t index, int value)
{
    if (v->capacity == v->size)
    {
        reserve(v, v->size + 1);
    }
    for (int i = v->size - 1; i > index - 1; i--)
    {
        v->data[i + 1] = v->data[i];
    }
    v->data[index] = value;
    v->size++;
}

/**
 * Удалить элемент на заданной позиции
 * @param v Вектор
 * @param index Позиция
 */
void erase(Vector *v, size_t index)
{
    Vector* new_vector = createVector(v->capacity - 1);
    for (int i = 0; i < index; i++)
    {
        new_vector->data[i] = v->data[i];
    }
    for (int i = index; i < v->size - 1; i++)
    {
        new_vector->data[i] = v->data[i + 1];
    }
    v->data = new_vector->data;
    v->size--;
    v->capacity--;
    delete new_vector;
}

/**
 * Найти первый элемент с заданным значением
 * и вернуть его индекс.
 * Если элемента нет, вернуть -1
 * @param v Вектор
 * @param value Значение
 */
size_t indexOf(Vector *v, int value)
{
    for (int i = 0; i < v->size; i++)
    {
        if (v->data[i] == value)
        {
            return static_cast<size_t>(i);
        }
    }
}

/**
 * Изменить размер выделенной памяти так,
 * чтобы он соответствовал
 * количеству элементов в векторе.
 * Если размер вектора равен нулю,
 * очистить память (delete[]).
 * @param v Вектор
 */
void squeeze(Vector *v)
{
    auto* new_vector = new Vector[v->size];
    memcpy(&new_vector, &v->data, v->size);
    v->data = new_vector->data;
    deleteVector(new_vector);
    v->capacity = v->size;
}

/**
 * Очистить вектор --- заполнить выделенную память нулями
 * и установить размер, равный нулю.
 * @param v Вектор
 */
void clear(Vector *v)
{
    for (int i = 0; i < v->capacity; i++)
    {
        v->data[i] = 0;
        v->size = 0;
    }
}

/**
 * Вывести в std::cout элементы массива,
 * последовательно, через пробел и запятую.
 * Пример:
 * 1, 2, 3, 4
 * @param v Вектор
 */
void print(Vector *v)
{
    for (int i = 0; i < v->size; i++)
        std :: cout << v->data[i];
}
#endif //UNILABS_VECTOR_H
