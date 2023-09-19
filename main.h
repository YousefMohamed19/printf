#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

int _printf(const char *format, ...);
int _putchar(char c);

/*0-task function */
int print_char(va_list ap, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list ap, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list ap, char buffer[], int flags, int width, int precision, int size);

#endif /* MAIN_H */
