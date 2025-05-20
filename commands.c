//
// Created by Andrii Klykavka on 11.05.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "commands.h"
#include "file_interaction.h"
#include "Buffer.h"

#define BUFFER_LINES 255
#define LINE_CHARS 255

char* readConsole() {

    size_t size = 0;
    size_t capacity = 16;
    char *input = malloc(capacity * sizeof(char));

    int ch;
    while((ch = getchar()) != '\n' && ch != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            char *newInput = realloc(input, capacity);
            if (newInput == NULL) {
                free(input);
                return NULL;
            }
            input = newInput;
        }
        input[size] = (char)ch;
        size++;
    }

    input[size] = '\0';
    return input;
}

void showInstructions() {
    printf("The list of instructions: \n");
    printf("0 - show the list of commands.\n");
    printf("1 - append text.\n");
    printf("2 - add new line.\n");
    printf("3 - save a file.\n");
    printf("4 - load a file.\n");
    printf("5 - print text.\n");
    printf("6 - insert in text by line and index.\n");
    printf("7 - search in text.\n");
    printf("8 - exit program\n");
}

void appendText(Buffer *buffer) {

    printf("Enter text to append: ");
    char *input = readConsole();
    buffer->append(buffer, input);
}

void addNewLine(Buffer *buffer) {
    buffer->addLine(buffer);
    printf("New line is started\n");
}

void saveFile(Buffer *buffer) {
    char path[20];
    printf("Enter file path for saving: ");
    scanf("%s", &path);

    writeFile(path, buffer);
}

void loadFile(Buffer *buffer) {
    char path[20];
    printf("Enter file path for loading: ");
    scanf("%s", &path);
    readFile(path, buffer);
}

void printText(Buffer *buffer) {
    buffer->print(buffer);
}

void insertByLineAndIndex(Buffer *buffer) {
    int lineIdx;
    int charIdx;

    printf("Enter line index and char index: ");
    if (scanf("%d %d", &lineIdx, &charIdx) == 2 && lineIdx >= 0 && charIdx >= 0) {
        printf("Line index: %d, Character index: %d\n", lineIdx, charIdx);
    } else {
        printf("Invalid input.\n");
        return;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);


    printf("Enter text to insert: ");
    char *input = readConsole();

    buffer->insert(buffer, lineIdx, charIdx, input);
}

void searchText(Buffer *buffer) {
    printf("Enter text to search for: ");
    char *input = readConsole();
    buffer->search(buffer, input);
}

void exitProgram() {
    printf("Exiting program...\n");
    exit(101);
}

void clearScreen() {
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}