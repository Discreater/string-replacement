#include "SBR.h"

#include <cassert>
#include <iostream>

namespace sbr {
SBRRepresentaion generate(limbType *const src, int size) {
    SBRRepresentaion res(size + 1);

    for (int i = 0; i < size; ++i) {
        res[i] = src[i];
    }

    // << 1
    for (int i = size; i > 0; i--) {
        res[i] = res[i - 1];
    }
    res[0] = 0;

    // temp = temp - src;
    for (int i = 0; i < size; i++) {
        res[i] = res[i] - src[i];
    }

    // sbr
    for (int i = size; i >= 2; i--) {
        auto biti = res[i];
        auto biti1 = res[i - 1];
        auto biti2 = res[i - 2];
#define COND(a, b, c) (biti == (a) && biti1 == (b) && biti2 == (c))
#define SET(a, b, c) {res[i] = (a); res[i - 1] = (b); res[i - 2] = (c);}
        if (COND(0, 1, -1)) {
            SET(0, 0, 1);
        } else if (COND(0, -1, 1)) {
            if (i > 2 && res[i - 3] == 0) {
                SET(0, 0, -1);
            }
        } else if (COND(1, 0, -1)) {
            if (i > 2 && res[i - 3] == 0) {
                SET(0, 1, 1);
            }
        } else if (COND(1, -1, 1)) {
            SET(0, 1, 1);
        } else if (COND(-1, 1, -1)) {
            SET(-1, 0, 1);
        } else if (COND(1, 1, -1)) {
            SET(1, 0, 1);
        }
    }
    return res;
}

void printLimb(SBRRepresentaion &limb, bool carry, const string &name) {
    int hamWeight = 0;
    if (carry)
        hamWeight += 1;
    cout << name << ":\n|";
    for (int i = limb.size() - 1; i >= 0; --i) {
        if (limb[i] != 0)
            ++hamWeight;
        cout << ((int32_t)limb[i]) << "|";
    }
    cout << "  hamWeight = " << hamWeight << "\n";
}

void powm(limbType &res, limbType g, limbType gInverse, SBRRepresentaion &e, limbType n) {

    limbType x = 1;
    for (int i = e.size() - 1; i >= 0; i--) {
        x = x * x % n;
        if (e[i] == 1) {
            x = x * g % n;
        } else if (e[i] == -1) {
            x = x * gInverse % n;
        }
    }
    res = x;
}
}  // namespace sbr
