#include <gmpxx.h>
#include <time.h>

#include <chrono>
#include <iostream>
#include <string>

#include "MOF.h"
#include "SBR.h"
#include "createLimb.h"
#include "naive_approach.h"
#include "readLimb.h"
#include "replacement.h"
#include "testPrint.h"

using namespace std;
using namespace std::chrono;

int main() {
    mpz_class c;

    gmp_randclass rr(gmp_randinit_default);
    mpz_class a = rr.get_z_bits(1024);
    mpz_class b = rr.get_z_bits(1024);

    cout << "a len: " << mpz_sizeinbase(a.get_mpz_t(), 2) << endl;
    cout << "a: " << a.get_str() << endl;
    cout << "b len: " << mpz_sizeinbase(b.get_mpz_t(), 2) << endl;
    cout << "b: " << b.get_str() << endl;

    auto start = system_clock::now();
    for (int i = 0; i < 100; i++) {
        mpz_powm(c.get_mpz_t(), a.get_mpz_t(), mpz_class(2).get_mpz_t(), b.get_mpz_t());
    }
    auto end = system_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << "cost time: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    cout << "res len: " << mpz_sizeinbase(c.get_mpz_t(), 2) << endl;
    cout << "a^2%b: " << c.get_str() << endl;
}