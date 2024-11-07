#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void){
    unsigned short quantity;
    printf("Quantity of numbers to print (max 65.535): ");
    scanf("%hu", &quantity);

    FILE *outputFile = fopen("random_list", "w");
    if (outputFile == NULL){
        printf("Bruh\n");
        return 1;
    }
    srand(time(0));
    
    char *bufferString;
    bufferString = (char*) malloc(25);
    for (int i = 0; i < quantity; i++){
        int randomNumber = rand();
        sprintf(bufferString, "%d", randomNumber);
        fprintf(outputFile, bufferString);
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);
    free(bufferString);

    return 0;
}
