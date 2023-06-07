#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void encrypt(char message[], int a, int b) {
    int i = 0;
    while (message[i]) {
        if (message[i] != ' ') {
            char ch = message[i];
            if (ch >= 'A' && ch <= 'Z') {
                ch = ((a * (ch - 'A') + b) % 26) + 'A';
            } else if (ch >= 'a' && ch <= 'z') {
                ch = ((a * (ch - 'a') + b) % 26) + 'a';
            }
            message[i] = ch;
        }
        i++;
    }
}

void decrypt(char message[], int a, int b) {
    int a_inv = modInverse(a, 26);
    int i = 0;
    while (message[i]) {
        if (message[i] != ' ') {
            char ch = message[i];
            if (ch >= 'A' && ch <= 'Z') {
                ch = ((a_inv * (ch - 'A' - b + 26)) % 26) + 'A';
            } else if (ch >= 'a' && ch <= 'z') {
                ch = ((a_inv * (ch - 'a' - b + 26)) % 26) + 'a';
            }
            message[i] = ch;
        }
        i++;
    }
}

int main() {
    char message[100];
    int a, b;

    printf("Enter the message to encrypt/decrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the value for 'a' (must be coprime with 26): ");
    scanf("%d", &a);

    printf("Enter the value for 'b': ");
    scanf("%d", &b);

    // Check if 'a' is coprime with 26
    if (gcd(a, 26) != 1) {
        printf("Error: 'a' is not coprime with 26. Choose another value.\n");
        return 0;
    }

    printf("\nOriginal message: %s", message);

    encrypt(message, a, b);
    printf("Encrypted message: %s", message);

    decrypt(message, a, b);
    printf("Decrypted message: %s", message);

    return 0;
}
