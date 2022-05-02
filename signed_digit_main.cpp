#include <iostream>
#include <string>
#include <time.h>
#include "replacement.h"
#include "testPrint.h"
#include "createLimb.h"
#include "naive_approach.h"
#include "MOF.h"

using namespace std;

// #define NAIVE
#define MOFH

int main()
{
    const int size = 50;
    int threshold = 2;
    // limbType oriLimb[50];
    limbType *oriLimb = new limbType[size];
#ifdef NAIVE
    limbType newLimb[50];
    bool carry = false;
#endif
#ifdef MOFH
    // limbType newLimb[51];
    limbType *newLimb = new limbType[size+1];
#endif

    srand(time(NULL));
    createLimb(oriLimb, size);
    printLimb(oriLimb, size, false, "oriLimb");
#ifdef NAIVE
    naive_string_replacement::replace(newLimb, carry, oriLimb, size, threshold);
    printLimb(newLimb, size, carry, "newLimb");
#endif

#ifdef MOFH
    MOF_replacement::replace(newLimb, oriLimb, size);
    printLimb(newLimb, size+1, false, "newLimb");
#endif

    // 测试数据
    limbType g = 27;
    limbType gInverse = 2;
    limbType n = 53;
    limbType res = 0;
#ifdef NAIVE
    naive_string_replacement::powm(res, g, gInverse, newLimb, carry, size, n);
#endif
#ifdef MOFH
    MOF_replacement::powm(res, g, gInverse, newLimb, size + 1, n);
#endif

    cout << "g^e mod n = " << res << endl;

    return 0;
}