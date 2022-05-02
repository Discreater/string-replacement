#pragma once
#include <iostream>
#include "replacement.h"

using namespace std;





namespace MOF_replacement
{
    void replace(limbType *newLimb, limbType *oriLimb, const int size);

    void substitutePattern(limbType *limb, const int size);
    
    void powm(limbType &res, limbType g, limbType gInverse, limbType *e, const int size, limbType n);
};