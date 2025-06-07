# CAESER CIPHER and RSA

## Short description or overview of the project.
   
   we worked on making a hybrid encryption system which uses caeser sipher and rsa . Our goal is to create a robust encryption system so that our files and means of communication are encrypted . We will be writing an encryption algorithm and then implementing it on plain text to show how RSA works.

## Table of Contents :-
    requirements
    Installation 
    Features
    Contributions

### Requirements
    GMP library
    GCC compiler

### Installation
    we used the gmp library witch is neccesarily requierd for caeser cipher and rsa encryption . 
    Here's the link for installing the gmp library :- https://gmplib.org/download/gmp/gmp-6.3.0.tar.xz


### features

    1. Asymmetric Encryption: RSA is an asymmetric encryption algorithm, meaning it uses two separate keys for encryption and decryption: a public key and a private key. The public key is used for encryption, while the private key is used for decryption. This allows for secure communication between parties without needing to share a secret key.

    2. Security: RSA encryption is based on the mathematical difficulty of factoring large prime numbers, specifically the RSA problem. It is considered secure due to the difficulty of factoring the product of two large prime numbers into their original primes. As long as the key sizes are chosen sufficiently large, RSA encryption provides strong security against attacks.

    3. Versatility: RSA encryption can be used in a wide range of applications, including secure communication protocols (e.g., SSL/TLS), digital signatures for authentication and integrity verification, secure email communication, secure file transfer, and more. Its versatility and security make it a popular choice for many cryptographic applications. 


## How to setup the project

   gcc yoursourcefiles.c -o test -lgmp
   ./test .
   
   
