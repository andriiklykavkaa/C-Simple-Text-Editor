//
// Created by Andrii Klykavka on 11.05.2025.
//

#include "commands.h"
#include <stdio.h>
#include <string.h>

char buffer[255][255];

void showInstructions() {
    printf("The list of instructions: \n");
    printf("0 - show the list of commands.\n");
    printf("1 - append text.\n");
    printf("2 - add new line.\n");
    printf("3 - save a file.\n");
    printf("4 - load a file..\n");
    printf("5 - print text in a file.\n");
    printf("6 - insert in text by line and index.\n");
    printf("7 - search in a file.\n");
}

void appendText() {
    char input[255];

    printf("Enter text to append: ");
    scanf(" %s", input);

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

void addNewLine() {

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

void saveFile() {

}

void loadFile() {

}

void printText() {
    for(int i = 0; i < 255; i++)
    {
        if (buffer[i][0] == '\0')
        {
            break;
        }
        printf("%s", buffer[i]);
    }
    printf("\n");
}

void insertByLineAndIndex() {

}

void searchText() {

}
