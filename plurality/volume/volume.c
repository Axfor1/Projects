// Modifies the volume of an audio file
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// Number of bytes in .wav header
const int HEADER_SIZE = 44;
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Use of: ./volume input.wav output.wav factor\n");
        return 1;
    }
// Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Can't open file.\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Can'topen file.\n");
        return 1;
    }
    float factor = atof(argv[3]);
// Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(&header, HEADER_SIZE, 1, input);
    fwrite(&header, HEADER_SIZE, 1, output);
// Read samples from input file and write updated data to output file
    int16_t buff;
    while (fread(&buff, sizeof(int16_t), 1, input))
    {
        // Applies factor to buffer
        buff *= factor;
        fwrite(&buff, sizeof(int16_t), 1, output);
    };
// Close files
    fclose(input);
    fclose(output);
}