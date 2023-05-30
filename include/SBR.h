#pragma once

#include <vector>

#include "replacement.h"

namespace sbr {
using SBRRepresentaion = vector<int8_t>;

SBRRepresentaion generate(limbType *const src, int size);

void printLimb(SBRRepresentaion &limb, bool carray, const string &name);
void powm(limbType &res, limbType g, limbType gInverse, SBRRepresentaion &e, limbType n);
}  // namespace sbr
