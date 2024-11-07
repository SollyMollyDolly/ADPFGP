#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"


//TODO: fix argument management
int main(int argc, char **argv){
    if (argc < 2 || argc > 3){
        printf("Usage: %s [FILE] [output]\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL){
        printf("Could not open file '%s' or '%s' does not exist\n", argv[1], argv[1]);
        return 1;
    }

    int numbersAmount = CountNumbers(input);
    int *numberList;
    numberList = (int *) malloc(numbersAmount * sizeof(int));

    for (int i = 0; i < numbersAmount; i++){
        fscanf(input, "%d", &numberList[i]);
    }
    fclose(input);
    
    MergeSort(numberList, 0, numbersAmount - 1);

    FILE *output = argc == 3 ? fopen(argv[2], "w") : fopen("output", "w");
    if (output == NULL){
        printf("Error creating output file\n");
        return 1;
    }


    for (int i = 0; i < numbersAmount; i++){
        fprintf(output, "%d", numberList[i]);
        fprintf(output, "\n");

    }

    printf("Sorted and printed %d numbers to %s\n", numbersAmount, argv[2]);
    fclose(output);
    free(numberList);
    return 0;
}
