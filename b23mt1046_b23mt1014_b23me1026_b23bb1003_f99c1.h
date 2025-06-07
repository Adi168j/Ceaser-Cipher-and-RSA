#ifndef B23MT1046_B23MT1014_B23ME1026_B23BB1003_F99C1_H
#define B23MT1046_B23MT1014_B23ME1026_B23BB1003_F99C1_H
#include<gmp.h>
void generate_odd_number(mpz_t rop);
int MR_witness(mpz_t check, mpz_t a, mpz_t r, mpz_t f);
int millerRabin_primalityTest(mpz_t ODD);

void get_prime(mpz_t Pr1);

#endif