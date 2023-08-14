#include <stdio.h>
#include <string.h>
#define SIZE 5
char matrix[SIZE][SIZE] = {
    {'K', 'E', 'Y', 'W', 'O'},
    {'R', 'D', 'A', 'B', 'C'},
    {'F', 'G', 'H', 'I', 'L'},
    {'M', 'N', 'P', 'Q', 'S'},
    {'T', 'U', 'V', 'X', 'Z'}
};
void encrypt(char plaintext[], char ciphertext[]) 
{
    int len = strlen(plaintext);
    int i, j, k;
    for (i = 0; i < len; i += 2) 
	{
        int row1, col1, row2, col2;
        for (j = 0; j < SIZE; j++) 
		{
            for (k = 0; k < SIZE; k++) 
			{
                if (matrix[j][k] == plaintext[i]) 
				{
                    row1 = j;
                    col1 = k;
                }
                if (matrix[j][k] == plaintext[i + 1]) 
				{
                    row2 = j;
                    col2 = k;
                }
            }
        }
        if (row1 == row2) 
		{
            ciphertext[i] = matrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        }
        else if (col1 == col2) 
		{
            ciphertext[i] = matrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        }
        else 
		{
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }
    ciphertext[i] = '\0';
}
int main() 
{
    char plaintext[] = "HELLO";
    char ciphertext[100];
    encrypt(plaintext, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted: %s\n", ciphertext);
    return 0;
}
