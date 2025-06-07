
#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "b23mt1046_b23mt1014_b23me1026_b23bb1003_f99c1.h"
#include "b23mt1046_b23mt1014_b23me1026_b23bb1003_rsa.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define MAX_LENGTH 255
int flag = 0;
void encrypto(char s[], int key)
{
    int i = 0;
    char ch;
    while (s[i] != '\0')
    {
        ch = s[i];
        if (isupper(ch))
        {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        else if (islower(ch))
        {
            ch = (ch - 'a' + key) % 26 + 'a';
        }
        // Skip encryption for digits and spaces
        else if (isdigit(ch) || ch == ' ' || !isalnum(ch))
        {
            // Do nothing
        }
        s[i] = ch;
        i++;
    }
}
void slow_print( char *str, int delay, const char *color)
{
    while (*str)
    {
        printf("  %s", color); // Set text color
        putchar(*str++);
        fflush(stdout); // Ensure characters are printed immediately
        usleep(delay);  // Delay in microseconds
    }
    printf(ANSI_COLOR_RESET); // Reset text color
}
void print_decr(char decrypted_ascii[], char Ascii[], int length, int key)
{
    printf("Decrypted Message:\n");
    for (int i = 0; i < length; i++)
    {
        int decrypted_ascii11;
        // Decrypt each ASCII value by subtracting the key

        if (Ascii[i] == ' ')
        {
            decrypted_ascii11 = Ascii[i];
        }
        else
        {
            // Apply key shift for letters
            decrypted_ascii11 = (int)decrypted_ascii[i] - key;
        }

        // Print the decrypted ASCII value as a character
        // printf("\n%d %d %d \n", decrypted_ascii11,decrypted_ascii[i],key);
        printf("%c", decrypted_ascii11);
    }
}

int main()
{

    char message[MAX_LENGTH];
    int Ascii[1000];

    printf(ANSI_COLOR_GREEN "                                      ********Welcome to our encryption decryption system *************                 \n\n\n\n" ANSI_COLOR_RESET);
    printf("Enter text  :");
    // scanf("%[^\n]", message);
    scanf(" %[^\n]%*c", message);
    char filename[100];
    srand(time(NULL));
    int key = rand() % 5;
    

    char enrypt[] = "Encrypting.......";
    char Denrypt[] = "Decrypting.......";
    //   slow_print(enrypt,100000,ANSI_COLOR_BLUE);
    //   slow_print(Denrypt,600000,ANSI_COLOR_GREEN);

    // printf("%d", key);

    // printf(" %s\n", message);

    encrypto(message, key);

    int decrypted_ascii[259];
    int length = 0;
    mpz_t p, q, n, A, e, d;

    mpz_init(p);
    mpz_init(q);
    mpz_init(n);
    mpz_init(A);
    mpz_init(e);
    mpz_init(d);
    mpz_t ajitek;
    mpz_init(ajitek);
    mpz_t up;
    mpz_init(up);
    get_prime(p);
    get_prime(q);
    while (mpz_cmp(p, q) == 0)
    {
        get_prime(q);
    }

    mpz_set_ui(e, 65537);
    // find_E(A, e);
    //   printf("bfdjfd");
    //  gmp_printf("%Zd \n %Zd \n",p,q);
    //  gmp_printf("%Zd \n",e);
    mpz_mul(n, p, q);

    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(A, p, q);

    // gmp_printf(" %Zd \n",A);

    find_D(d, e, A);
    // printf("Breakpoint\n");
    int asci;
    store_key(n, e, d);
 
    int option;
    while (option != 3)
    {

        printf(ANSI_COLOR_RED "Choose an option:\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "1. Encrypt Message\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "2.  Decrypt Message\n" ANSI_COLOR_RESET);
        printf("Enter option :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            if (flag == 0)
            {
                slow_print(enrypt, 100000, ANSI_COLOR_BLUE);
                printf("\n");

                for (int i = 0; message[i] != '\0'; i++)
                {
                    Ascii[i] = (int)message[i];

                    // mpz_set_ui(e,65537);

                    // printf("Enter number to be encrypted:- ");
                    // scanf("%d",&asci);
                    // printf("\n");
                    encrypt(n, e, Ascii[i], ajitek);
                    decrypt(n, d, ajitek, up);

                    decrypted_ascii[i] = mpz_get_ui(up);
                    length++;

                    // printf("%c", decrypted_ascii);
                }
            }

            else
            {
                printf("You have Already encrypted the message");
                printf("\n");
            }
            flag = 1;

             mpz_clear(ajitek);
            mpz_clear(p);
            mpz_clear(q);
            mpz_clear(n);
            mpz_clear(A);
            mpz_clear(e);
            mpz_clear(d);
            break;
        case 2:
            if (flag == 1)
            {
                slow_print(Denrypt, 300000, ANSI_COLOR_GREEN);
                printf("\n");
                printf("Decrypted Message:\n");
                for (int i = 0; i < length; i++)
                {
                    int decrypted_ascii11;
                    // Decrypt each ASCII value by subtracting the key

                    if (Ascii[i] == ' ')
                    {
                        decrypted_ascii11 = Ascii[i];
                    }
                    else
                    {
                        // Apply key shift for letters
                        decrypted_ascii11 = (int)decrypted_ascii[i] - key;
                    }

                    
                    // printf("\n%d %d %d \n", decrypted_ascii11,decrypted_ascii[i],key);
                    printf("%c", decrypted_ascii11);
                }

                printf("\n");
            }
            else
            {
                printf("You have not encrypted  the message yet");
                printf("\n");
            }

            break;
        default:
            printf("Invalid option!\n");
              getchar();
             
              break;
        }
    }

   
    printf("\n"); // Print a newline aft
    return 0;
}