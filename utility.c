#include "myShell.h"

char* _fgets(char* str, int num, FILE* stream) {
    char* result = fgets(str, num, stream);
    if (result == NULL) {
        return NULL;
    }

    // Check for newline character
    char* newline_pos = _strchr(str, '\n');
    if (newline_pos != NULL) {
        *newline_pos = '\0';
    }
    else {
        // If no newline character found, flush input buffer
        int c;
        while ((c = _getchar()) != '\n' && c != EOF);
    }

    return str;
}
