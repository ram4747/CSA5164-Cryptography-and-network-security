#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function to encrypt plaintext using row-column cipher technique
void rowColumnCipherEncrypt(char plaintext[], int rows, int cols, char ciphertext[]) {
    char grid[MAX][MAX];
    int len = strlen(plaintext);
    
    // Initialize the grid with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = ' ';
        }
    }
    
    // Fill the grid with plaintext
    int index = 0;
    for (int i = 0; i < rows && index < len; i++) {
        for (int j = 0; j < cols && index < len; j++) {
            grid[i][j] = plaintext[index++];
        }
    }
    
    // Read the grid column-wise
    index = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (grid[i][j] != ' ') {
                ciphertext[index++] = grid[i][j];
            }
        }
    }
    ciphertext[index] = '\0';
}

// Function to decrypt ciphertext using row-column cipher technique
void rowColumnCipherDecrypt(char ciphertext[], int rows, int cols, char plaintext[]) {
    char grid[MAX][MAX];
    int len = strlen(ciphertext);
    
    // Initialize the grid with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = ' ';
        }
    }
    
    // Fill the grid with ciphertext column-wise
    int index = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (index < len) {
                grid[i][j] = ciphertext[index++];
            }
        }
    }
    
    // Read the grid row-wise
    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != ' ') {
                plaintext[index++] = grid[i][j];
            }
        }
    }
    plaintext[index] = '\0';
}

int main() {
    char plaintext[MAX], ciphertext[MAX], decryptedtext[MAX];
    int rows, cols;
    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove newline character from plaintext if present
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len-1] == '\n') {
        plaintext[len-1] = '\0';
    }
    
    printf("Enter number of rows for the grid: ");
    scanf("%d", &rows);
    printf("Enter number of columns for the grid: ");
    scanf("%d", &cols);
    
    // Encrypt the plaintext
    rowColumnCipherEncrypt(plaintext, rows, cols, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    
    // Decrypt the ciphertext
    rowColumnCipherDecrypt(ciphertext, rows, cols, decryptedtext);
    printf("Decrypted plaintext: %s\n", decryptedtext);
    
    return 0;
}