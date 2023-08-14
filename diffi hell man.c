#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Function to calculate the power of a number modulo another number
long long int power(long long int base, long long int exponent, long long int modulus) {
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 0) 
	{
        long long int temp = power(base, exponent / 2, modulus);
        return (temp * temp) % modulus;
    } 
	else 
	{
        long long int temp = power(base, exponent - 1, modulus);
        return (base * temp) % modulus;
    }
}
int main() 
{
    long long int prime = 7;
    long long int primitive_root = 5;
    // Private keys for Alice and Bob
    long long int private_a = 3; // Private key for Alice
    long long int private_b = 4; // Private key for Bob
    // Calculate public keys for Alice and Bob
    long long int public_a = power(primitive_root, private_a, prime);
    long long int public_b = power(primitive_root, private_b, prime);
    // Calculate shared secret for Alice and Bob
    long long int secret_a = power(public_b, private_a, prime);
    long long int secret_b = power(public_a, private_b, prime);
    printf("Publicly Shared Prime: %lld\n", prime);
    printf("Primitive Root: %lld\n", primitive_root);
    printf("\nPrivate Key of Alice: %lld\n", private_a);
    printf("Private Key of Bob: %lld\n", private_b);
    printf("\nPublic Key of Alice: %lld\n", public_a);
    printf("Public Key of Bob: %lld\n", public_b);
    printf("\nShared Secret for Alice: %lld\n", secret_a);
    printf("Shared Secret for Bob: %lld\n", secret_b);
    return 0;
}

