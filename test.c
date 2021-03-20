#include <stdio.h>

int main(){
    FILE *file = fopen("calendar-notes.txt", "rb+");
    char text[100];
    fread(&text, sizeof(text), 1, file);
    fclose(file);
    printf("%s", text);
    return 0;
}