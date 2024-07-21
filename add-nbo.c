#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t shift(uint32_t n) {
    return ((n & 0xFF000000) >> 24) |
           ((n & 0x00FF0000) >> 8) |
           ((n & 0x0000FF00) << 8) |
           ((n & 0x000000FF) << 24);
}

uint32_t read_file(const char* filename) {
    FILE *file = fopen(filename, "rb");
    uint32_t number;
    if (file == NULL){
	    perror("error opening file");
	    exit(EXIT_FAILURE);
    }

    size_t read_size = fread(&number, sizeof(uint32_t), 1, file);
    if (read_size != 1) {
        perror("Error reading file");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    return shift(number);
}

int main() {
    char file1[100], file2[100];

    printf("input your path for file1: ");
    scanf("%99s", file1);

    printf("input your path for file2: ");
    scanf("%99s", file2);

    uint32_t num1 = read_file(file1);
    uint32_t num2 = read_file(file2);

    uint32_t sum = num1 + num2;
   
    printf("%u (0x%x) + %u (0x%x) = %u (0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

