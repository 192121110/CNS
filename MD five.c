#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define LEFT_ROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    uint8_t buffer[64];
} MD5_CTX;

void md5_init(MD5_CTX *ctx) {
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
    ctx->count[0] = ctx->count[1] = 0;
}

void md5_update(MD5_CTX *ctx, const uint8_t *input, size_t input_len) {
    // TODO: Implement this function
}

void md5_final(MD5_CTX *ctx, uint8_t digest[16]) {
    // TODO: Implement this function
}

int main() {
	int i;
    MD5_CTX ctx;
    uint8_t input[] = "Hello, MD5!";
    uint8_t digest[16];

    md5_init(&ctx);
    md5_update(&ctx, input, strlen((char *)input));
    md5_final(&ctx, digest);

    printf("MD5 Hash: ");
    for (i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}

