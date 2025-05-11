//
// Created by Andrii Klykavka on 11.05.2025.
//

#include <stdio.h>
#include <string.h>

void readFile(char path[], char buffer[255][255])
{
    char line[255];
    int i = 0;

    FILE * file;
    file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Error opening file at path '%s'", path);
    }
    else
    {
        for (int j = 0; j < 255; j++) {
            buffer[j][0] = '\0';
        }

        while (fgets(line, sizeof(line), file))
        {
            strcpy(buffer[i], line);
            i++;
        }

        fclose(file);
        printf("File was loaded successfully!\n");
    }
}

void writeFile(char path[], char buffer[255][255])
{
    FILE* file;
    file = fopen(path, "w");
    if (file != NULL)
    {
        int i = 0;
        while(buffer[i][0] != '\0')
        {
            fputs(buffer[i], file);
            fputc('\n', file);
            i++;
        }

        fclose(file);
    } else
    {
        printf("Error saving data to file!");
    }
}