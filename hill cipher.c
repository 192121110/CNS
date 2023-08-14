#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 10
int keyMatrix[MAX_SIZE][MAX_SIZE];
int messageVector[MAX_SIZE];
int encryptedVector[MAX_SIZE];
int decryptedVector[MAX_SIZE];
void getKeyMatrix(char key[], int keySize) 
{
    int i,j,k = 0;
    for (i = 0; i < keySize; i++) 
	{
        for ( j = 0; j < keySize; j++) 
		{
            keyMatrix[i][j] = key[k++] - 'a';
        }
    }
}
void encrypt(int keySize) 
{
	int i,j;
    for (i = 0; i < keySize; i++) 
	{
        int sum = 0;
        for (j = 0; j < keySize; j++) 
		{
            sum += keyMatrix[i][j] * messageVector[j];
        }
        encryptedVector[i] = sum % 26;
    }
}
void decrypt(int keySize, int inverseMatrix[][MAX_SIZE]) 
{
	int i,j;
    for (i = 0; i < keySize; i++) 
	{
        int sum = 0;
        for (j = 0; j < keySize; j++) 
		{
            sum += inverseMatrix[i][j] * encryptedVector[j];
        }
        decryptedVector[i] = (sum % 26 + 26) % 26;
    }
}
int main() 
{
    int i,j,keySize;
    char key[MAX_SIZE * MAX_SIZE];
    char message[MAX_SIZE];
    printf("Enter key size (max %d): ", MAX_SIZE);
    scanf("%d", &keySize);
    printf("Enter key matrix (lowercase letters only):\n");
    for (i = 0; i < keySize * keySize; i++) 
	{
        scanf(" %c", &key[i]);
    }
    getKeyMatrix(key, keySize);
    printf("Enter the message to be encrypted (lowercase letters only): ");
    scanf("%s", message);
    int messageLength = strlen(message);
    if (messageLength % keySize != 0) 
	{
        printf("Message length is not compatible with the key size.\n");
        return 1;
    }
    for (i = 0; i < messageLength; i++) 
	{
        messageVector[i % keySize] = message[i] - 'a';
        if (i % keySize == keySize - 1) 
		{
            encrypt(keySize);
            for (j = 0; j < keySize; j++) 
			{
                printf("%c", encryptedVector[j] + 'a');
            }
        }
    }
    printf("\n");
    int determinant = keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0];
    int inverseMatrix[MAX_SIZE][MAX_SIZE];
    int temp = keyMatrix[0][0];
    keyMatrix[0][0] = keyMatrix[1][1];
    keyMatrix[1][1] = temp;
    keyMatrix[0][1] = -keyMatrix[0][1];
    keyMatrix[1][0] = -keyMatrix[1][0];
    for (i = 0; i < keySize; i++) 
	{
        for (j = 0; j < keySize; j++) 
		{
            inverseMatrix[i][j] = (keyMatrix[i][j] * (int)pow(determinant, -1)) % 26;
            if (inverseMatrix[i][j] < 0) 
			{
                inverseMatrix[i][j] += 26;
            }
        }
    }
    printf("Decrypted message: ");
    for ( i = 0; i < messageLength; i++) 
	{
        encryptedVector[i % keySize] = message[i] - 'a';
        if (i % keySize == keySize - 1) 
		{
            decrypt(keySize, inverseMatrix);
            for (j = 0; j < keySize; j++) 
			{
                printf("%c", decryptedVector[j] + 'a');
            }
        }
    }
    printf("\n");
    return 0;
}

