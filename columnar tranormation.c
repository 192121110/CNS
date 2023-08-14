#include <stdio.h>
#include <string.h>
void columnarEncrypt(char *message, char *key, char *encrypted) 
{
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int rows = (messageLen + keyLen - 1) / keyLen;
    int i,j,k;
    char matrix[rows][keyLen];
    for (i = 0, k = 0; i < rows; i++) 
	{
        for ( j = 0; j < keyLen; j++) 
		{
            if (k < messageLen) 
			{
                matrix[i][j] = message[k++];
            } 
			else 
			{
                matrix[i][j] = 'X';  
            }
        }
    }
    int keyOrder[keyLen];
    for (i = 0; i < keyLen; i++) 
	{
        keyOrder[i] = i;
    }
    for (i = 0; i < keyLen - 1; i++)
	{
        for (j = i + 1; j < keyLen; j++) 
		{
            if (key[keyOrder[i]] > key[keyOrder[j]]) 
			{
                int temp = keyOrder[i];
                keyOrder[i] = keyOrder[j];
                keyOrder[j] = temp;
            }
        }
    }
    int encryptedIndex = 0;
    for (i = 0; i < keyLen; i++) 
	{
        for (j = 0; j < rows; j++) 
		{
            encrypted[encryptedIndex++] = matrix[j][keyOrder[i]];
        }
    }
    encrypted[encryptedIndex] = '\0';
}
void columnarDecrypt(char *encrypted, char *key, char *decrypted) 
{
    int encryptedLen = strlen(encrypted);
    int keyLen = strlen(key);
    int rows = encryptedLen / keyLen;
    int i,j;
    char matrix[rows][keyLen];
    int keyOrder[keyLen];
    for (i = 0; i < keyLen; i++) 
	{
        keyOrder[i] = i;
    }
    for (i = 0; i < keyLen - 1; i++) 
	{
        for (j = i + 1; j < keyLen; j++) 
		{
            if (key[keyOrder[i]] > key[keyOrder[j]])
			{
                int temp = keyOrder[i];
                keyOrder[i] = keyOrder[j];
                keyOrder[j] = temp;
            }
        }
    }
    int decryptedIndex = 0;
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < keyLen; j++) 
		{
            matrix[i][keyOrder[j]] = encrypted[decryptedIndex++];
        }
    }
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < keyLen; j++) 
		{
            decrypted[i * keyLen + j] = matrix[i][j];
        }
    }
    decrypted[encryptedLen] = '\0';
}
int main() 
{
    char message[] = "HELLO WORLD";
    char key[] = "KEY";
    char encrypted[100];
    columnarEncrypt(message, key, encrypted);
    printf("Encrypted: %s\n", encrypted);
    char decrypted[100];
    columnarDecrypt(encrypted, key, decrypted);
    printf("Decrypted: %s\n", decrypted);
    return 0;
}
