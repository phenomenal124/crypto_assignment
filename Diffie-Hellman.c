#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the modulo exponentiation (a^b mod p)
int mod_exp(int a, int b, int p) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return (int)res;
}

// Function to generate symmetric key using Diffie-Hellman
int generate_symmetric_key(int g, int p, int x, int y) {
    // Calculate the shared secret for both parties
    int secret1 = mod_exp(y, x, p);
    int secret2 = mod_exp(g, x, p);

    if (secret1 == secret2) {
        printf("Shared secret: %d\n", secret1);
        return secret1; // Return the shared secret as the symmetric key
    } else {
        printf("Error: Shared secrets do not match!\n");
        return -1;
    }
}

int main() {
    int g, p, x, y;

    printf("Enter the value of g: ");
    scanf("%d", &g);

    printf("Enter the value of p: ");
    scanf("%d", &p);

    printf("Enter the private key for party X (x): ");
    scanf("%d", &x);

    printf("Enter the private key for party Y (y): ");
    scanf("%d", &y);

    int symmetric_key = generate_symmetric_key(g, p, x, y);

    if (symmetric_key != -1) {
        printf("Symmetric key: %d\n", symmetric_key);
    } else {
        printf("Error occurred during key generation.\n");
    }

    return 0;
}
