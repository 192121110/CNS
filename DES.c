#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>

void generateSymmetricKey(unsigned char *skey, char *knum) {
    DES_key_schedule des_key;
    DES_cblock key;
    memcpy(key, knum, 8);

    DES_set_odd_parity(&key);
    DES_set_key_checked(&key, &des_key);

    memcpy(skey, &des_key, sizeof(des_key));
}

void encrypt(const unsigned char *skey, const unsigned char *input, size_t input_len, unsigned char *output) {
    DES_key_schedule des_key;
    memcpy(&des_key, skey, sizeof(des_key));

    DES_ecb_encrypt((DES_cblock *)input, (DES_cblock *)output, &des_key, DES_ENCRYPT);
}

void decrypt(const unsigned char *skey, const unsigned char *input, size_t input_len, unsigned char *output) {
    DES_key_schedule des_key;
    memcpy(&des_key, skey, sizeof(des_key));

    DES_ecb_encrypt((DES_cblock *)input, (DES_cblock *)output, &des_key, DES_DECRYPT);
}

int main() {
    unsigned char skey[8];
    char knum[] = "12345678";  // 8-character key

    generateSymmetricKey(skey, knum);

    char inputMessage[1000];
    printf("Enter message to encrypt: ");
    scanf("%s", inputMessage);

    size_t input_len = strlen(inputMessage);
    unsigned char encryptedData[1000];
    encrypt(skey, (unsigned char *)inputMessage, input_len, encryptedData);

    printf("Encrypted message: ");
    for (size_t i = 0; i < input_len; i++) {
        printf("%02X", encryptedData[i]);
    }
    printf("\n");

    unsigned char decryptedMessage[1000];
    decrypt(skey, encryptedData, input_len, decryptedMessage);

    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}

