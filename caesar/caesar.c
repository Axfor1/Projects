#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool o_d(string text);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    int k, length;
    string text;
    if (argc != 2 || !o_d(argv[1]))
    {
        printf("Usage: ./caesar with number\n");
        return 1;
    }
    k = atoi(argv[1]);
    text = get_string("text: ");
    length = strlen(text);
    char ciphertext[length + 1];
    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = rotate(text[i], k);
    }
    ciphertext[length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool o_d(string text)
{
    int length;

    length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}
char rotate(char p, int k)
{
    char pi, c, ci;
    if (isupper(p))
    {
        pi = p - 65;
        ci = (pi + k) % 26;
        c = ci + 65;
    }
    else if (islower(p))
    {
        pi = p - 97;
        ci = (pi + k) % 26;
        c = ci + 97;
    }
    else
    {
        return p;
    }
    return c;

}