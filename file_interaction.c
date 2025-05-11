//
// Created by Andrii Klykavka on 11.05.2025.
//

#include <stdio.h>

void readFile(char path[])
{
    FILE * file;
    char textString[255];

    file = fopen("path", "r");
    if (file == NULL)
    {
        printf("Error opening file at path '%s'", path);
    }
    else
    {
        if (fgets(textString, 255, file) != NULL)
        {
            printf("%s", textString);
        }
        fclose(file);
    }
}

void writeFile(char path[], char text[])
{
    printf("We begin the process of saving:\n");
    printf("%s\n", text);
    printf("%s\n", path);

    FILE* file;
    file = fopen(path, "w");
    printf("%d", file == NULL);
    if (file != NULL)
    {
        fputs(text, file);
        fclose(file);
    }
}