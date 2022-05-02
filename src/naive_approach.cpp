#include <iostream>
#include "replacement.h"
#include "naive_approach.h"

using namespace std;


namespace naive_string_replacement
{
    void replace(limbType *newLimb, bool &carry, limbType *oriLimb, const int size, const int threshold)
    {
        for (int i = 0; i < size; ++i)
        {
            newLimb[i] = oriLimb[i];
        }
        while (hasConsecutiveOnes(newLimb, size, threshold) == true)
        {
            int startLimb = 0;
            // 记录连续1的数量
            int cnt = 0;

            int cur = 0;
            while (cur < size)
            {
                if (newLimb[cur] == 1)
                {
                    ++cnt;
                }
                else if (newLimb[cur] == 0)
                {
                    // LSB -> MSB
                    if (cnt >= threshold) //
                    {
                        newLimb[startLimb] = -1;
                        for (int i = startLimb + 1; i < cur; ++i)
                        {
                            newLimb[i] = 0;
                        }
                        newLimb[cur] = 1;
                    }
                    cnt = 0;
                    startLimb = cur + 1;
                }
                ++cur;
            }
            if (cnt >= threshold)
            {
                newLimb[startLimb] = -1;
                for (int i = startLimb + 1; i < cur; ++i)
                {
                    newLimb[i] = 0;
                }
                carry = 1;
            }
        }
    }

    bool hasConsecutiveOnes(limbType *Limb, const int size, const int threshold)
    {
        int cnt = 0;
        for (int i = 0; i < size; ++i)
        {
            if (cnt >= threshold)
            {
                return true;
            }
            if (Limb[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
        }
        if (cnt > threshold)
            return true;
        return false;
    }

    void powm(limbType &res, limbType g, limbType gInverse, limbType *e, bool carry, int size, limbType n)
    {
        limbType x = 1;

        if (carry)
        {
            x = x * g % n;
        }
        for (int i = size - 1; i >= 0; --i)
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
