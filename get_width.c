#include "main.h"

/**
 * _width_get_func - Calculates the width for printing
 * @frmt: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int _width_get_func(const char *frmt, int *i, va_list list)
{
	int cr_i;
	int wth = 0;

	for (cr_i = *i + 1; frmt[cr_i] != '\0'; cr_i++)
	{
		if (_is_d(frmt[cr_i]))
		{
			wth *= 10;
			wth += frmt[cr_i] - '0';
		}
		else if (frmt[cr_i] == '*')
		{
			cr_i++;
			wth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cr_i - 1;

	return (wth);
}
