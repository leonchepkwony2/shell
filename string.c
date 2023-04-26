#include "myShell.h"


size_t _strlen(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char* _strchr(const char* str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char*) str;
        }
        str++;
    }
    if (c == '\0') {
        return (char*) str;
    }
    return NULL;
}

int _getchar(void) {
    static char buf[BUFSIZ];
    static char* bufp = buf;
    static int n = 0;
    if (n == 0) {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int _strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] < str2[i]) ? -1 : 1;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }
    else {
        return (str1[i] < str2[i]) ? -1 : 1;
    }
}

