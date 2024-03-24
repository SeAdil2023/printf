#include "main.h"


/**
 * print_the_chr - Prints a char
 * @type: List a of arguments
 * @buffer: Buffer array to handle
 * @fls:  Calculate flag
 * @width: Width
 * @pre: pre specification
 * @size: Size specif
 * Return: Number of chars printed
 */
int print_the_chr(va_list type, char buffer[],
	int fls, int width, int pre, int size)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, buffer, fls, width, pre, size));
}

/**
 * str_prnt - Prints a string
 * @type: List a of arguments
 * @buffer: Buffer array to handle
 * @fls:  Calculates active flags
 * @width: get width.
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int str_prnt(va_list type, char buffer[],
	int fls, int width, int pre, int size)
{
	int length = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(buffer);
	UNUSED(fls);
	UNUSED(width);
	UNUSED(pre);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (pre >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (pre >= 0 && pre < length)
		length = pre;

	if (width > length)
	{
		if (fls & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * prcnt_prnt - Prints a percent sign
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @fls:  Calculates active flags
 * @width: get width.
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars
 */
int prcnt_prnt(va_list type, char buffer[],
	int fls, int width, int pre, int size)
{
	UNUSED(type);
	UNUSED(buffer);
	UNUSED(fls);
	UNUSED(width);
	UNUSED(pre);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * integer_print - Print int
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @fls:  Calculates active flags
 * @width: get width.
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int integer_print(va_list type, char buffer[],
	int fls, int width, int pre, int size)
{
	int i = BUFF_SIZE - 2;
	int is_ngtve = 0;
	long int j = va_arg(type, long int);
	unsigned long int number;

	j = _sz_nmbr_convert(j, size);

	if (j == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)j;

	if (j < 0)
	{
		number = (unsigned long int)((-1) * j);
		is_ngtve = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_number(is_ngtve, i, buffer, fls, width, pre, size));
}


/**
 * bnar_prnt - Prints an unsigned number
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @fls:  Calculates active flags
 * @width: get width.
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int bnar_prnt(va_list type, char buffer[],
	int fls, int width, int pre, int size)
{
	unsigned int n, k, i, m;
	unsigned int arr[32];
	int c;

	UNUSED(buffer);
	UNUSED(fls);
	UNUSED(width);
	UNUSED(pre);
	UNUSED(size);

	n = va_arg(type, unsigned int);
	k = 2147483648; 
	arr[0] = n / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		arr[i] = (n / m) % 2;
	}
	for (i = 0, m = 0, c = 0; i < 32; i++)
	{
		m += arr[i];
		if (m || i == 31)
		{
			char r = '0' + arr[i];

			write(1, &r, 1);
			c++;
		}
	}
	return (c);
}
