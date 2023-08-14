#include <stdio.h>
#include <string.h>
void encrypt(char text[], int shift) 
{
    int i,length = strlen(text);    
    for (i = 0; i < length; i++) 
	{
        if (text[i] >= 'a' && text[i] <= 'z') 
		{
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        } 
		else if (text[i] >= 'A' && text[i] <= 'Z') 
		{
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        }
    }
}
void decrypt(char text[], int shift)
{
    encrypt(text, 26 - shift);   
}
int main() 
{
    char text[100];
    int shift;
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    encrypt(text, shift);
    printf("Encrypted text: %s", text);
    decrypt(text, shift);
    printf("Decrypted text: %s", text);
    return 0;
}
