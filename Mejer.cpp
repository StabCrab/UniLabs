//
// Created by trykr on 06.11.2019.
//
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> array;
    size_t size = 9;
    int a;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        array.push_back(a);
    }
    bool is_iterative = false;
    bool is_no_iterative = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (array[i] == array[j])
            {
                is_iterative = true;
            }
        }
        if (!is_iterative)
        {
            array.erase(array.begin() + i);
            i--;
            size--;
        }
        else
        {
            is_no_iterative = false;
            for (int j = size - 1; j > i; j--)
            {
                if (array[i] == array[j])
                {
                    array.erase(array.begin() + j);
                    size--;
                }
            }
        }
        is_iterative = false;
    }
    if (is_no_iterative)
    {
        cout << "ERROR";
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }
}

