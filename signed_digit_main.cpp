#include <iostream>
#include <string>
#include <time.h>
#include "replacement.h"
#include "naive_approach.h"
#include "testPrint.h"
#include "createLimb.h"

using namespace std;

int main()
{
    const int size = 10;
    int threshold = 2;
    limbType oriLimb[10];
    limbType newLimb[10];
    bool carry = false;

    srand(time(NULL));
    createLimb(oriLimb, size);
    printLimb(oriLimb, size, "oriLimb");
    naive_string_replacement::replace(newLimb, carry, oriLimb, size, threshold);
    printLimb(newLimb, size, "newLimb");

    // 测试数据
    limbType g = 27;
    limbType gInverse = 2; 
    limbType n = 53;
    limbType res = 0;
    naive_string_replacement::powm(res, g, gInverse, newLimb, carry, size, 53);

    cout << "g^e = " << res << endl;


    return 0;
}