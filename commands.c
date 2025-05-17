//
// Created by Andrii Klykavka on 11.05.2025.
//

#include "commands.h"
#include "file_interaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_LINES 255
#define LINE_CHARS 255

char buffer[BUFFER_LINES][LINE_CHARS];

void showInstructions()
{
    printf("The list of instructions: \n");
    printf("0 - show the list of commands.\n");
    printf("1 - append text.\n");
    printf("2 - add new line.\n");
    printf("3 - save a file.\n");
    printf("4 - load a file..\n");
    printf("5 - print text in a file.\n");
    printf("6 - insert in text by line and index.\n");
    printf("7 - search in a file.\n");
    printf("8 - exit program\n");
}

void appendText()
{
    char input[255];

    printf("Enter text to append: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int lastLine = 0;
    for(int i = 0; i < 255; i++)
    {
        if (buffer[i][0] == '\0')
        {
            break;
        }
        lastLine = i;
    }

    strcat(buffer[lastLine], input);
}

void addNewLine()
{

    int lastLine = 0;
    for(int i = 0; i < 255; i++)
    {
        if (buffer[i][0] == '\0')
        {
            break;
        }
        lastLine = i;
    }

    strcat(buffer[lastLine], "\n");
    printf("New line is started\n");
}

void saveFile()
{
    char path[20];
    printf("Enter file path for saving: ");
    scanf("%s", &path);

    writeFile(path, buffer);
}

void loadFile()
{
    char path[20];
    printf("Enter file path for loading: ");
    scanf("%s", &path);
    readFile(path, buffer);
}

void printText()
{
    for(int i = 0; i < 255; i++)
    {
        if (buffer[i][0] == '\0')
        {
            break;
        }
        printf("%s", buffer[i]);
    }
}

void insertByLineAndIndex()
{
    int lineIndex;
    int charIndex;

    printf("Enter line index and char index: ");
    if (scanf("%d %d", &lineIndex, &charIndex) == 2 &&
        lineIndex >= 0 &&
        charIndex >= 0 &&
        (lineIndex == 0 || buffer[lineIndex-1][0] != '\0') &&
        (charIndex == 0 || buffer[lineIndex][charIndex-1] != '\0')) {
        printf("Line index: %d, Character index: %d\n", lineIndex, charIndex);
    } else {
        printf("Invalid input.\n");
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    char *line = buffer[lineIndex];
    int length = strlen(line);

    char text[255];
    printf("Enter text to insert: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    int textLength = strlen(text);

    if(length + textLength > LINE_CHARS)
    {
        printf("Operation error. Line length will be too long.\n");
        return;
    }

    memmove(line + charIndex + textLength, line + charIndex, length - (charIndex) + 1);
    memcpy(line + charIndex, text, textLength);
}

void searchText()
{

}

void exitProgram()
{
    printf("Exiting program...\n");
    exit(101);
}