//
// Created by Andrii Klykavka on 11.05.2025.
//

#ifndef COMMAND_H
#define COMMAND_H


#include "Buffer.h"

char* readConsole();
void showInstructions();
void appendText(Buffer *buffer);
void addNewLine(Buffer *buffer);
void saveFile(Buffer *buffer);
void loadFile(Buffer *buffer);
void printText(Buffer *buffer);
void insertByLineAndIndex(Buffer *buffer);
void searchText(Buffer *buffer);
void exitProgram();
void clearScreen();

#endif //COMMAND_H
