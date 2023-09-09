#include "../std_lib_facilities.h"
#include "RSA.H"
#include <climits> //access constants UCHAR_MAX = 255 USHRT_MAX = 65535

int main() {  
    //declare variables
    unsigned long long p, q, n, lambda, d, e, m, c;
    unsigned int seed;

    //Ask the user to enter a seed
    cout << "Enter a seed: ";
    cin >> seed;
    cout << endl;

    //Call srand() ONCE to seed your RNG
    srand(seed);

    /*
    getPrime assigns p and q a random prime number in range UCHAR_MAX to USHRT_MAX
    255 to 65535, between 8 and 16 bits in length
    Output the values of p and q
    */
    p = getPrime(UCHAR_MAX, USHRT_MAX);
    q = getPrime(UCHAR_MAX, USHRT_MAX);
    cout << "p: " << p << endl
         << "q: " << q << endl;
    
    /*
    The modulus n is obtained by multiplying the two large prime numbers, p and q
    Output the value of n
    */
    n = p * q;
    cout << "n: " << n << endl;

    /*
    The next steps use modular arithmetic number theory to generate the variables.
    Assign lambda to the lcm of p - 1 and q - 1
    Output the value of lambda
    Lambda is used to generate e and d
    */
    lambda = lcm(p -1, q - 1);
    cout << "lambda: " << lambda << endl;

    /*
    e must be a prime smaller than lambda that does not divide evenly into lambda
    getPrime assigns to e, a random prime in the range [2...lambda - 1]
    While lambda is divisible by e, assign to e a new random prime
    Output the value of e
    */
    e = getPrime(2, lambda - 1); //prime the loop
    while ((lambda % e) == 0) {
        e = getPrime(2, lambda - 1);
    }
    cout << "e: " << e << endl;

    /*assign to d the modInverse of e and lambda
    Output the value of d
    */
    d = modInverse(e, lambda);
    cout << "d: " << d << endl;
    
    //Output the public key and the private key
    cout << "Public key: n = " << n << " e = " << e << endl
         << "Private key: n = " << n << " d = " << d << endl;
    
    /*
    Prompt the user to enter the plain message m, input to assign m
    */
    cout << "Enter a positive number less than " << n << ": " << endl;
    cin >> m;

    /*
    Use modExp to assign to cipher c the modular exponent m^e % n
    This is your encrypted value, which is what a client would send to a server
    Output the value of the cipher
    */    

    c = modExp(m, e, n);
    cout << "Cipher: " << c << endl;

    /*
    Decrypt and output the cipher c by calculating the modular exponent c^d % n
    You should get the original message m
    This is what the server, having the private key d and n, would do to decrypt the client's message
    */
    cout << "Decrypted cipher: " << modExp(c, d, n) << endl;

    return 0;
}