#include <iostream>
#include "replacement.h"
#include "MOF.h"

using namespace std;

namespace MOF_replacement
{
    void replace(limbType *newLimb, limbType *oriLimb, const int size)
    {
        // size of newLimb = size of oriLimb + 1
        newLimb[size] = oriLimb[size - 1];
        for (int i = size - 1; i >= 1; --i)
        {
            newLimb[i] = oriLimb[i - 1] - oriLimb[i];
        }
        newLimb[0] = -1 * oriLimb[0];
        substitutePattern(newLimb, size + 1);
    }

    void substitutePattern(limbType *limb, const int size)
    {

        int i = size - 1;
        while (i >= 1)
        {
            // 1 | -1
            if (limb[i] == 1 && limb[i - 1] == -1)
            {
                limb[i] = 0;
                limb[i - 1] = 1;
            }
            // -1 | 1
            else if (limb[i] == -1 && limb[i - 1] == 1)
            {
                limb[i] = 0;
                limb[i - 1] = -1;
            }
            --i;
        }
    }

    void powm(limbType &res, limbType g, limbType gInverse, limbType *e, const int size, limbType n)
    {
        limbType x = 1;

        for (int i = size; i >= 0; --i)
        {
            x = x * x % n;
            if (e[i] == 1)
            {
                x = x * g % n;
            }
            else if (e[i] == -1)
            {
                x = x * gInverse % n;
            }
        }
        res = x;
    }
};