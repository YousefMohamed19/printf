#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    const char *ptr;
    int count = 0;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            switch (*(ptr + 1))
            {
            case 'd':
            case 'i':
            {
                int num = va_arg(args, int);
                char buffer[12]; // Assuming a 32-bit integer
                int length = snprintf(buffer, 12, "%d", num);
                write(1, buffer, length);
                count += length;
                break;
            }
            default:
                break;
            }
            ptr++;
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
    }

    va_end(args);
    return count;
}
