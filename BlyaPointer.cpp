//
// Created by trykr on 29.10.2019.
//

#include<iostream>
using namespace std;
void swap(double* first, double* second)
{
    double *third = second;
    second = first;
    first = third;
}
void bubbleSort(double* arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }
    }
}
int binarySearch(double* arr, double value, size_t first, size_t last)
{
    size_t middle = last - first;
    while (arr[middle] != value)
    {
        middle = last - first;
        if (value < arr[middle])
            first = middle - 1;
        else
            last = middle - 1;
    }
        return static_cast<int>(middle);
}
double* diff(double* arr, size_t arrSize, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = arr[i + 1] * (i + 1);
        }
        arr[arrSize - 1] = 0;
        arrSize--;
    }
    return arr;
}
void printPolynom(double* arr)
{
    if (arr[0] != 0)
        cout << arr[0] << " + ";
    for (int i = 1; i < 4; i++)
    {
        if (arr[i] == 0)
            continue;
        cout << arr[i] << "* x^" << i << ' ';
    }
}
int main()
{

}