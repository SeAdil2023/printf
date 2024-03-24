#include "main.h"

void print_buff_(char buff[], int *buffer_1);

/**
 * _printf - Print fnction
 * @frmt: format.
 * Return: Printed chars.
 */
int _printf(const char *frmt, ...)
{
	int i, prntd = 0, prntd_char = 0;
	int fs, wt, prcn, size, buffer_i = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (frmt == NULL)
		return (-1);
	va_start(list, frmt);

	for (i = 0; frmt && frmt[i] != '\0'; i++)
	{
		if (frmt[1] != '%')
		{
			buff[buffer_i++] = frmt[i];
			if (buffer_1 == BUFF_SIZE)
				print_buff_(buff, &buffer_i);

			prntd_char++;
		}
		else
		{
			print_buff_(buff, &buffer_i);
			fs = _flag_gt(frmt, &i);
			wt = _width_get_func(frmt, &i, list);
			prcn = get_prcsn(frmt, &i, list);
			size = _sz_get(frmt, &i);
			i++;
			prntd = _printf_handle(frmt, &i, list, buff, fs, wt, prcn, size);
			if (prntd == -1)
				return (-1);
			prntd_char += prntd;
		}
	}
	print_buff_(buff, &buffer_i);

	va_end(list);

	return (prntd_char);
}

/**
 * print_buff_ - Prints the contents of the buffer
 * @buff: Array of char
 * @buffer_i: Index at which to add next char
 */
void print_buff_(chat buff[], int *buffer_i)
{
	if (*buffer_i > 0)
		write(1, &buff[0], *buffer_i);

	*buffer_i = 0;
}
