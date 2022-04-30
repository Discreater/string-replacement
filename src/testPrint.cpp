#include <iostream>
#include <string>
#include "replacement.h"
#include "testPrint.h"

using namespace std;

void printLimb(limbType *limb, int size, string limbName)
{
    int hamWeight = 0;
    cout << limbName << ":\n|";
    for (int i = 0; i < size; ++i)
    {
        if (limb[i] != 0)
            ++hamWeight;
        cout << limb[i] << "|";
    }
    cout << "  hamWeight = " << hamWeight << "\n";
}