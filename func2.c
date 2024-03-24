#include "main.h"


/**
 * nsignd_prnt - Prints an unsigned number
 * @type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int nsignd_prnt(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);

	number = _sz_unsgnd_convert(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = (number % 10) + '0';
		number /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flag, width, pre, size));
}

/**
 * _octlprnt - Prints an unsigned number in octal notation
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _octlprnt(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = _sz_unsgnd_convert(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = (number % 8) + '0';
		number /= 8;
	}

	if (flag & F_HASH && init_number != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flag, width, pre, size));
}


/**
 * hexa_prnt - Prints an unsigned number in hexadecimal notation
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_prnt(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	return (prnt_hx(type, "0123456789abcdef", buffer,
		flag, 'x', width, pre, size));
}


/**
 * prnthexa_up - Prints an unsigned number in upper hexadecimal notation
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prnthexa_up(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	return (prnt_hx(type, "0123456789ABCDEF", buffer,
		flag, 'X', width, pre, size));
}


/**
 * prnt_hx - Prints a hexadecimal number in lower or upper
 * @type: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @flag_ch: Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int prnt_hx(va_list type, char map_to[], char buffer[],
	int flag, char flag_ch, int width, int pre, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = _sz_unsgnd_convert(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = map_to[number % 16];
		number /= 16;
	}

	if (flag & F_HASH && init_number != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flag, width, pre, size));
}
