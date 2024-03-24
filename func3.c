nclude "main.h"


/**
 * prnt_ptr - Prints the value of a pointer variable
 * @type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int prnt_ptr(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	char extra_char = 0, paadd = ' ';
	int innd = BUFF_SIZE - 2, l = 2, pad_st = 1; 
	unsigned long number_address;
	char _map[] = "0123456789abcdef";
	void *address = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(pre);

	number_address = (unsigned long)address;

	while (number_address > 0)
	{
		buffer[innd--] = _map[number_address % 16];
		number_address /= 16;
		l++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		paadd = '0';
	if (flag & F_PLUS)
		extra_char = '+', l++;
	else if (flag & F_SPACE)
		extra_char = ' ', l++;

	innd++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, innd, l,
		width, flag, paadd, extra_char, pad_st));
}


/**
 * prnt_n_prntbl - Prints ascii codes in hexa of non printable chars
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prnt_n_prntbl(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	int a = 0, o_set = 0;
	char *string = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(pre);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[a] != '\0')
	{
		if (prntbl(string[a]))
			buffer[a + o_set] = string[a];
		else
			o_set += apnd_hexa(string[a], buffer, a + o_set);

		a++;
	}

	buffer[a + o_set] = '\0';

	return (write(1, buffer, a + o_set));
}


/**
 * _rev_prnt - Prints reverse string.
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int _rev_prnt(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	char *string;
	int i, c = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(type, char *);

	if (string == NULL)
	{
		UNUSED(pre);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		c++;
	}
	return (c);
}

/**
 * prnt_rot13_str - Print a string in rot13.
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width
 * @pre: pre specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int prnt_rot13_str(va_list type, char buffer[],
	int flag, int width, int pre, int size)
{
	char y;
	char *string;
	unsigned int i, j;
	int c = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outt[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(type, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(pre);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == string[i])
			{
				y = outt[j];
				write(1, &y, 1);
				c++;
				break;
			}
		}
		if (!in[j])
		{
			y = string[i];
			write(1, &y, 1);
			c++;
		}
	}
	return (c);
}
