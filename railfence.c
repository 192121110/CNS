#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int rails, char *ciphertext) 
{
    int length = strlen(plaintext);
    int i,j;
    for (i = 0; i < rails; i++) 
	{
        for (j = i; j < length; j += rails) 
		{
            ciphertext[strlen(ciphertext)] = plaintext[j];
        }
    }

    ciphertext[length] = '\0';
}
int main() 
{
    char plaintext[1000];
    int rails;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    char ciphertext[1000] = "";
    railFenceEncrypt(plaintext, rails, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    return 0;
}
