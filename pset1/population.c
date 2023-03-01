#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int i;
    do
    {
        i = get_int("Start size: \n");
    }
    while (i < 9);

    // TODO: Prompt for end size
    int j;
    do
    {
        j = get_int("End_size: \n");
    }
    while (j <= i);

    // TODO: Calculate number of years until we reach threshold
    int present_size = i;
    int years_passed = 0;
    while (present_size < j)
    {
        present_size = round(present_size + present_size/3 - present_size/4);
        years_passed++;
    }

    // TODO: Print number of years
    printf("Years: %i \n", years_passed);
}
