#include <stdio.h>
#include <stdint.h>
#include <string.h>

void xor_encrypt(const char *input, uint8_t key, uint8_t *output) {
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }
    output[len] = '\0';
}

int main() {
    char input[256];
    uint8_t key;
    uint8_t output[256];

    printf("Enter a string to convert: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    printf("Enter XOR key (0-255): ");
    if (scanf("%hhu", &key) != 1) {
        printf("Invalid key input.\n");
        return 1;
    }
    xor_encrypt(input, key, output);
    printf("XOR-encrypted format:\n");
    for (size_t i = 0; i < strlen(input); i++) {
        printf("0x%02X, ", output[i]);
    }
    printf("\n");

    return 0;
}
