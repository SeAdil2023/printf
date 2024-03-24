#include "main.h"

/**
 * prntbl - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int prntbl(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * apnd_hexa - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @asciicd: ASSCI CODE.
 * Return: Always 3
 */
int apnd_hexa(char asciicd, char buffer[], int i)
{
	char map_t[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (asciicd < 0)
		asciicd *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_t[asciicd / 16];
	buffer[i] = map_t[asciicd % 16];

	return (3);
}

/**
 * _is_d - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _is_d(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * _sz_nmbr_convert - Casts a number to the specified size
 * @nmber: Number to be casted.
 * @sz: Number indicating the type to be casted.
 *
 * Return: Casted value of nmber
 */
long int _sz_nmbr_convert(long int nmber, int sz)
{
	if (sz == S_LONG)
		return (nmber);
	else if (sz == S_SHORT)
		return ((short)nmber);

	return ((int)nmber);
}

/**
 * _sz_unsgnd_convert - Casts a number to the specified size
 * @nmber: Number to be casted
 * @sz: Number indicating the type to be casted
 *
 * Return: Casted value of nmber
 */
long int _sz_unsgnd_convert(unsigned long int nmber, int sz)
{
	if (sz == S_LONG)
		return (nmber);
	else if (sz == S_SHORT)
		return ((unsigned short)nmber);

	return ((unsigned int)nmber);
}
