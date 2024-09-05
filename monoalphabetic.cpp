#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to create substitution map
void createSubstitutionMap(char *key, char *map) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        map[i] = key[i];
    }
}

// Function to encrypt plaintext using the substitution map
void encrypt(char *plaintext, char *map, char *ciphertext) {
    int i = 0;  // Initialize index for ciphertext
    while (*plaintext) {
        if (isalpha(*plaintext)) {
            char base = islower(*plaintext) ? 'a' : 'A';
            ciphertext[i++] = map[tolower(*plaintext) - 'a'];
        } else {
            ciphertext[i++] = *plaintext;
        }
        plaintext++;
    }
    ciphertext[i] = '\0';
}

// Function to decrypt ciphertext using the reverse of the substitution map
void decrypt(char *ciphertext, char *map, char *plaintext) {
    char reverseMap[ALPHABET_SIZE];
    int i;

    // Initialize reverse map with placeholder values
    for (i = 0; i < ALPHABET_SIZE; i++) {
        reverseMap[i] = '?';  // Placeholder for unmapped values
    }

    // Create reverse substitution map
    for (i = 0; i < ALPHABET_SIZE; i++) {
        char index = tolower(map[i]) - 'a';
        reverseMap[index] = 'a' + i;
    }

    i = 0;  // Initialize index for plaintext
    while (*ciphertext) {
        if (isalpha(*ciphertext)) {
            char base = islower(*ciphertext) ? 'a' : 'A';
            char decryptedChar = reverseMap[tolower(*ciphertext) - 'a'];
            plaintext[i++] = isupper(*ciphertext) ? toupper(decryptedChar) : decryptedChar;
        } else {
            plaintext[i++] = *ciphertext;
        }
        ciphertext++;
    }
    plaintext[i] = '\0';
}

int main() {
    char key[ALPHABET_SIZE + 1];
    char plaintext[100];
    char ciphertext[100];
    char decryptedtext[100];

    // Example key (substitution map) for demonstration
    // The key should be a permutation of the alphabet
    printf("Enter substitution key (26 unique letters): ");
    scanf("%26s", key);

    // Validate key length
    if (strlen(key) != ALPHABET_SIZE) {
        printf("Key must be exactly 26 characters long.\n");
        return 1;
    }

    // Create substitution map
    char map[ALPHABET_SIZE];
    createSubstitutionMap(key, map);

    // Encrypt plaintext
    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);
    encrypt(plaintext, map, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt ciphertext
    decrypt(ciphertext, map, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}