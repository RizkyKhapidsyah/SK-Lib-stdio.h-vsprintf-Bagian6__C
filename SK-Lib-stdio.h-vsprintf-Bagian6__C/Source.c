#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

void test(char const* const format, ...) {
    va_list args;
    int len;
    char* buffer;

    va_start(args, format);
    len = _vscprintf(format, args) // _vscprintf doesn't count
        + 1; // terminating '\0'
    buffer = (char*)malloc(len * sizeof(char));

    if (NULL != buffer) {
        vsprintf_s(buffer, len, format, args);
        puts(buffer);
        free(buffer);
    }

    va_end(args);
}

int main() {
    test("%d %c %d", 123, '<', 456);
    test("%s", "This is a string");

    _getch();
    return 0;
}