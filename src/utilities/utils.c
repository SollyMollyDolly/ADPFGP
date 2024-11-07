int CountNumbers(FILE *file){
    char character;
    int numberCount = 0;

    while ((character = fgetc(file)) != EOF){
        if (character == '\n' || character == '\t' || character == ' '){
            numberCount++;
        }
    }
    
    rewind(file);
    return numberCount;
}
