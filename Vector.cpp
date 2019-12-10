//
// Created by trykr on 23.10.2019.
//
#include "Vector.h"
#include <cstdint>
#include <cstring>
using namespace std;
int main()
{
    Vector* a = createVector(6);
    for (int i = 0; i < 6; i++)
    {
        a->data[i] = i;
    }
    auto* b = new int[6];
    for (int i = 0; i < 6; i++)
    {
        b[5 - i] = i;
    }
    insert(a, 3, 9);
    erase(a, 3);
    print(a);
}
