#include <iostream>
#include <gmpxx.h>
#include "replacement.h"

using namespace std;

void readLimb(limbType *res, size_t *size, mpz_class &num)
{
    mpz_export(res, size, -1, sizeof(limbType), 0, 0, num.get_mpz_t());
}

void readLimbStr(limbType *&res, size_t &size, mpz_class &num)
{
    string str;
    str = num.get_str(2);
    size = str.size();
    res = new limbType[size];
    for (int i = 0; i < size; ++i)
    {
        res[i] = str[i] - '0';
    }
}