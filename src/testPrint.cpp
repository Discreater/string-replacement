#include <iostream>
#include <string>
#include "replacement.h"
#include "testPrint.h"

using namespace std;

void printLimb(limbType *limb, int size, bool carry, string limbName)
{
    int hamWeight = 0;
    if(carry)
        hamWeight += 1;
    cout << limbName << ":\n|";
    for (int i = size-1; i >= 0; --i)
    {
        if (limb[i] != 0)
            ++hamWeight;
        cout << limb[i] << "|";
    }
    cout << "  hamWeight = " << hamWeight << "\n";
}