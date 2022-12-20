#include <stdarg.h>
#include <stdio.h>

#define ANSI_ARG_FUNC(name, pattern, buffer_size) \
    inline const char *ANSI_##name(...) \
    { \
        static char buffer[buffer_size] = { 0 }; \
        va_list args; \
        sprintf(buffer, pattern, args);  \
        return buffer; \
    }