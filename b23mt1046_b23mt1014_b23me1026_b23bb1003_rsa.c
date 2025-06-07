#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include "b23mt1046_b23mt1014_b23me1026_b23bb1003_f99c1.h"

// create header files
// display encrypted data in hexadecimal form
// upper limit of data to be checked and padding is necessary

void find_E(mpz_t A, mpz_t e)
{
    mpz_t gcd, flag;
    mpz_init(gcd);
    mpz_init(flag);

    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, (unsigned long int)time(NULL));
    mpz_urandomm(flag, state, A);
    mpz_add_ui(flag, flag, 1);

    mpz_gcd(gcd, A, flag);

    if (mpz_cmp_ui(gcd, 1))
    {
        mpz_set(e, flag);
        // gmp_printf(" %Zd \n", e);

        mpz_clear(flag);
    }
    else
    {
        find_E(A, e);
    }

    mpz_clear(gcd);
    //  mpz_clear(flag);
}

// void find_D(mpz_t d, mpz_t e, mpz_t A) {
//     mpz_invert(d, e, A);
//     //gmp_printf(" %Zd ", d);
// }
void find_D(mpz_t d, mpz_t e, mpz_t A)
{
    mpz_t Q;
    mpz_init(Q);
    mpz_set(Q, A);
    mpz_invert(d, e, Q); // to bemade a separte function by oneself
    // gmp_printf(" %Zd \n", d);
    mpz_clear(Q);
}

// void find_A_n(mpz_t p,mpz_t q,mpz_t A,mpz_t n){

//     mpz_mul(n,p,q);
//     mpz_sub_ui(p,p,1);
//     mpz_sub_ui(q,q,1);
//     mpz_mul(A,p,q);

// }

void encrypt(mpz_t n, mpz_t e, int asci, mpz_t ajitek)
{
    mpz_t text_flag, rem, flag1;
    mpz_init(text_flag);
    mpz_init(rem);
    mpz_init(flag1);

    mpz_set_ui(flag1, (unsigned long)asci);

    mpz_powm_ui(text_flag, flag1, (unsigned long int)mpz_get_ui(e), n);

    // mpz_mod_ui(rem, text_flag, mpz_get_ui(n));

    // gmp_printf("%Zd \n", text_flag);
    mpz_set(ajitek, text_flag);
    // gmp_printf("%Zd \n",ajitek);
    char *hex_str;
    hex_str = mpz_get_str(NULL, 16, ajitek);

    // Print the hexadecimal representationk80
    printf("Hexadecimal representation: %s\n", hex_str);
    mpz_t remainder;
    //     mpz_clear(text_flag);
    //     mpz_clear(rem);
    //   mpz_clear(flag1);
}

void decrypt(mpz_t n, mpz_t d, mpz_t ajitek, mpz_t up)
{
    mpz_t text_flag1, rem, flag1;
    mpz_init(text_flag1);

    mpz_powm(text_flag1, ajitek, d, n); // to be written Separately as a fnction

    mpz_set(up, text_flag1);
    // gmp_printf("%Zd \n", text_flag1);
    //   mpz_clear(text_flag1);
    //   mpz_clear(rem);
    //   mpz_clear(flag1);
}
void store_key(mpz_t n, mpz_t e, mpz_t d)
{
    FILE *fp;
    fp = fopen("rsa_key.txt", "a+");
    if (fp != NULL)
    {
        gmp_fprintf(fp, "Public Key (n, e): (%Zd, %Zd)\n", n, e);
        gmp_fprintf(fp, "Private Key: %Zd\n", d);
        fclose(fp);
    }
}
