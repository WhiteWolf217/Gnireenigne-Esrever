#include <stdio.h>
#include <stdint.h>
#include <string.h>

void xor_decrypt(const uint8_t *input, size_t len, uint8_t key, char *output) {
    for (size_t i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }
    output[len] = '\0';
}

int main() {
    uint8_t input[256];
    char output[256];
    uint8_t key;
    size_t len;

    printf("Enter the number of encrypted bytes: ");
    if (scanf("%zu", &len) != 1 || len > sizeof(input)) {
        printf("Invalid length.\n");
        return 1;
    }

    printf("Enter the XOR key (0-255): ");
    if (scanf("%hhu", &key) != 1) {
        printf("Invalid key input.\n");
        return 1;
    }

    printf("Enter the encrypted bytes (as hex, separated by spaces): ");
    for (size_t i = 0; i < len; i++) {
        unsigned int byte;
        if (scanf("%x", &byte) != 1 || byte > 0xFF) {
            printf("Invalid byte input.\n");
            return 1;
        }
        input[i] = (uint8_t)byte;
    }
    xor_decrypt(input, len, key, output);
    printf("Decrypted string: %s\n", output);

    return 0;
}
