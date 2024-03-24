#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
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
 * struct frmt - Struct op
 *
 * @frmt: The format.
 * @fn: The function associated.
 */
struct frmt
{
	char frmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct frmt frmt_t - Struct op
 *
 * @frmt: The format.
 * @fm_t: The function associated.
 */
typedef struct frmt frmt_t;

int _printf(const char *format, ...);
int _print_handle(const char *frmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_the_chr(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int str_prnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prcnt_prnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int integer_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int bnar_prnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nsignd_prnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _octlprnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hexa_prnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnthexa_up(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int prnt_hx(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int prnt_n_prntbl(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int prnt_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int _flag_gt(const char *format, int *i);
int _width_get_func(const char *format, int *i, va_list list);
int get_prcsn(const char *format, int *i, va_list list);
int _sz_get(const char *format, int *i);

/*Function to print string in reverse*/
int _rev_prnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int prnt_rot13_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int prntbl(char);
int apnd_hexa(char, char[], int);
int _is_d(char);

long int _sz_nmbr_convert(long int num, int size);
long int _sz_unsgnd_convert(unsigned long int num, int size);

#endif /* MAIN_H */
