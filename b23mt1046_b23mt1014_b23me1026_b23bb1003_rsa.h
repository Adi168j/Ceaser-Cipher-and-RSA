#ifndef B23MT1046_B23MT1014_B23ME1026_B23BB1003_RSA_H
#define B23MT1046_B23MT1014_B23ME1026_B23BB1003_RSA_H
#include<gmp.h>

void find_E(mpz_t A, mpz_t e);
void find_D(mpz_t d, mpz_t e, mpz_t A);

void encrypt(mpz_t n, mpz_t e, int asci,mpz_t ajitek);
void decrypt(mpz_t n, mpz_t d, mpz_t ajitek, mpz_t ui);
void store_key(mpz_t n, mpz_t e, mpz_t d);



#endif