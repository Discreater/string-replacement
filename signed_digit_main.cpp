#include <iostream>
#include <string>
#include <time.h>
#include <gmpxx.h>
#include "replacement.h"
#include "testPrint.h"
#include "createLimb.h"
#include "readLimb.h"
#include "naive_approach.h"
#include "MOF.h"

using namespace std;

// #define NAIVE
#define MOFH
// #define TESTGMP

mpz_class genRandom(int bits)
{
    clock_t time = clock();
    mpz_class r;
    gmp_randclass rr(gmp_randinit_default);
    rr.seed(time);
    r = rr.get_z_bits(bits);
    mpz_setbit(r.get_mpz_t(), bits - 1);
    return r;
}

int main()
{
    srand(time(NULL));
#ifdef TESTGMP
    mpz_class p, q, N;
    p = genRandom(512);
    q = genRandom(512);
    mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
    mpz_nextprime(q.get_mpz_t(), q.get_mpz_t());
    N = p * q;
    size_t sizeN = 0;
    limbType *n_naive;
    readLimbStr(n_naive, sizeN, N);
    printLimb(n_naive, sizeN, false, "p*q");
    limbType *new_n_naive = new limbType[sizeN];
    bool n_carry = false;
    naive_string_replacement::replace(new_n_naive, n_carry, n_naive, sizeN, 2);
    printLimb(new_n_naive, sizeN, n_carry, "N");

    return 0;
#endif

    const int size = 10;
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
    limbType g = 52;
    limbType gInverse = 213;
    limbType n = 443;
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