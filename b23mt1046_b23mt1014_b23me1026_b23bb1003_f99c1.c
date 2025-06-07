#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_BITS 1024
gmp_randstate_t state;
void generate_odd_number(mpz_t rop)
{
    mpz_urandomb(rop, state, NUM_BITS);
    mpz_setbit(rop, 0);
    mpz_setbit(rop, NUM_BITS - 1);
}

int MR_witness(mpz_t check, mpz_t a, mpz_t r, mpz_t f)
{
    mpz_t x, check_m1;
    mpz_init(x);
    mpz_init(check_m1);
    mpz_sub_ui(check_m1, check, 1);
    mpz_powm(x, a, f, check);
    if (mpz_cmp(x, check_m1) == 0 || mpz_cmp_ui(x, 1) == 0)
    {
        mpz_clear(x);
        return 0;
    }
    for (int it = 1; it < mpz_get_ui(r); it++)
    {
        mpz_mul(x, x, x);
        mpz_mod(x, x, check);
        // gmp_printf("%Zd %Zd\n",x,check);
        if (mpz_cmp(x, check_m1) == 0)
        {
            mpz_clear(x);
            return 0;
        }
    }
    mpz_clear(x);
    return 1;
}

int millerRabin_primalityTest(mpz_t ODD)
{
    mpz_t r, f, ODD_1, rem_1;
    mpz_init(r);
    mpz_init(f);
    mpz_init(ODD_1);
    mpz_init(rem_1);
    mpz_set(ODD_1, ODD);
    mpz_sub_ui(f, ODD_1, 1);
    mpz_mod_ui(rem_1, f, 2);
    while (mpz_cmp_ui(rem_1, 0) == 0)
    {
        mpz_add_ui(r, r, 1);
        mpz_fdiv_q_ui(f, f, 2);
        mpz_mod_ui(rem_1, f, 2);
    }
    // int bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    mpz_t base, g;
    mpz_init(base);
    mpz_init(g);
    for (int i = 0; i < 200; i++)
    {
        // int a = bases[i];
        mpz_urandomm(base, state, ODD);
        mpz_gcd(g, base, ODD);
        if (mpz_cmp_ui(g, 1) > 0)
        {
            return 0;
        }
        if (MR_witness(ODD_1, base, r, f))
        {
            mpz_clear(r);
            mpz_clear(f);
            mpz_clear(ODD_1);
            mpz_clear(rem_1);
            return 0;
        }
        // gmp_printf("%Zd %Zd\n",ODD_1,base);
    }
    mpz_clear(r);
    mpz_clear(f);
    mpz_clear(ODD_1);
    mpz_clear(rem_1);
    return 1;
}

// void primeCnf(mpz_t prime) {
//     int x = 1;
//     mpz_init(prime);
//     generate_odd_number(prime);
//     printf("Generated odd number: ");
//     gmp_printf("%Zd\n", prime);
//     if (millerRabin_primalityTest(prime) == 1) {
//         printf("Probably prime\n");
//     } else {
//         printf("Composite\n");
//     }
//     mpz_clear(prime);
// }

void get_prime(mpz_t Pr1)
{
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, (unsigned long int)time(0));

    mpz_t P;
    mpz_init(P);
    // mpz_set_ui(P, 667);
    generate_odd_number(P);
    while (millerRabin_primalityTest(P) == 0)
    {
        generate_odd_number(P);
    }
    mpz_set(Pr1, P);
    mpz_clear(P);
}