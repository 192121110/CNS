#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareKey(char *key, char *keyMatrix) 
{
    int i, j, k;
    int keyLen = strlen(key);
    int keyIndex = 0;
    int used[26] = {0};
    for (i = 0; i < keyLen; i++) 
	{
        if (key[i] == 'j') 
		{
            key[i] = 'i';
        }
        if (!used[key[i] - 'a']) 
		{
            keyMatrix[keyIndex++] = key[i];
            used[key[i] - 'a'] = 1;
        }
    }
    for (i = 0; i < 26; i++) 
	{
        if (i != ('j' - 'a') && !used[i]) 
		{
            keyMatrix[keyIndex++] = 'a' + i;
        }
    }
}
void constructTable(char *keyMatrix, char table[SIZE][SIZE]) 
{
    int i,j,k = 0;
    for (i = 0; i < SIZE; i++) 
	{
        for (j = 0; j < SIZE; j++) 
		{
            table[i][j] = keyMatrix[k++];
        }
    }
}
void getCharPosition(char table[SIZE][SIZE], char ch, int *row, int *col) 
{
    if (ch == 'j') 
	{
        ch = 'i'; 
    }
    int i,j;
    for (i = 0; i < SIZE; i++) 
	{
        for (j = 0; j < SIZE; j++) 
		{
            if (table[i][j] == ch) 
			{
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encrypt(char table[SIZE][SIZE], char *message, char *cipher) 
{
    int len = strlen(message);
    int i = 0;
    while (i < len) 
	{
        int row1, col1, row2, col2;
        getCharPosition(table, message[i], &row1, &col1);
        getCharPosition(table, message[i + 1], &row2, &col2);
        if (row1 == row2) 
		{
            cipher[i] = table[row1][(col1 + 1) % SIZE];
            cipher[i + 1] = table[row2][(col2 + 1) % SIZE];
        } 
		else if (col1 == col2) 
		{
            cipher[i] = table[(row1 + 1) % SIZE][col1];
            cipher[i + 1] = table[(row2 + 1) % SIZE][col2];
        } 
		else 
		{
            cipher[i] = table[row1][col2];
            cipher[i + 1] = table[row2][col1];
        }
        i += 2;
    }
    cipher[len] = '\0';
}
void decrypt(char table[SIZE][SIZE], char *cipher, char *message) 
{
    int len = strlen(cipher);
    int i = 0;
    while (i < len) 
	{
        int row1, col1, row2, col2;
        getCharPosition(table, cipher[i], &row1, &col1);
        getCharPosition(table, cipher[i + 1], &row2, &col2);
        if (row1 == row2) 
		{
            message[i] = table[row1][(col1 - 1 + SIZE) % SIZE];
            message[i + 1] = table[row2][(col2 - 1 + SIZE) % SIZE];
        } 
		else if (col1 == col2) 
		{
            message[i] = table[(row1 - 1 + SIZE) % SIZE][col1];
            message[i + 1] = table[(row2 - 1 + SIZE) % SIZE][col2];
        } 
		else 
		{
            message[i] = table[row1][col2];
            message[i + 1] = table[row2][col1];
        }
        i += 2;
    }
    message[len] = '\0';
}
int main() 
{
    char key[100];
    char message[1000];
    char cipher[1000];
    char decrypted[1000];
    char keyMatrix[26];
    char table[SIZE][SIZE];
    printf("Enter the key : ");
    scanf("%s", key);
    prepareKey(key, keyMatrix);
    constructTable(keyMatrix, table);
    printf("Enter the message to be encrypted : ");
    scanf("%s", message);
    encrypt(table, message, cipher);
    printf("Encrypted message: %s\n", cipher);
    decrypt(table, cipher, decrypted);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}
