#include "stdarg.h"
#include "stdio.h"

#define MY_LOGFILE "/var/tmp/log"
void logtofile(char *fmt, ...)
{
    FILE* f;
    va_list args;
    char buf[2048] = {0};

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf)-1, fmt, args);
    va_end(args);

    f = fopen(MY_LOGFILE, "a+");
    fprintf(f, "%s\n", buf);
    fclose(f);
}
