#pragma once
#include <iostream>
#include <gmpxx.h>
#include "replacement.h"

using namespace std;

void readLimb(limbType *res, size_t *size, mpz_class &num);

void readLimbStr(limbType *&res, size_t &size, mpz_class &num);