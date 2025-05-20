//
// Created by Andrii Klykavka on 11.05.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Buffer.h"

void readFile(char *path, Buffer *buffer) {
    buffer->free(buffer);
    buffer->lines = malloc(sizeof(TextLine) * 8);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error opening file at path '%s'", path);
        return;
    }

    char *line = NULL;
    size_t len = 0;
    size_t read;

    buffer->height = 0;

    while((read = getline(&line, &len, file)) != -1) {
        if (read > 0 && line[read - 1 ] == '\n') {
            line[read - 1] = '\0';
        }

        buffer->addLine(buffer);
        buffer->append(buffer, line);
    }

    free(line);
    fclose(file);
    printf("File downloaded.\n");
}

void writeFile(char *path, Buffer *buffer) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        printf("Error creating file at path: %s", path);
        return;
    }

    char newLine = '\n';
    for(int i = 0; i < buffer->height; i++) {
        fwrite(buffer->lines[i].text, sizeof(char), buffer->lines[i].size, file);
        fputs(&newLine, file);
    }

    fclose(file);
    printf("File saved.\n");
}