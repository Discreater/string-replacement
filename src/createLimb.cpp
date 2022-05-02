#include <iostream>
#include "replacement.h"


void createLimb(limbType *limb, int size)
{
    for(int i = 0; i < size; ++i)
    {
        limb[i] = rand() % 2;
    }
    limb[size-1] = 1;
}