#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, s, r, c;
//loop prompt
    do
    {
        height = get_int("Input height here: ");
    }
    while (height < 1 || height > 8);
//r=row
    for (r = 0; r < height; r++)
    {
        for (s = 0; s < height - r - 1; s++)
        {
            printf(" ");
        }
//c = column
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}