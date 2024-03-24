#include "main.h"

/**
 * get_prcsn - Calculates the precision for printing
 * @frmt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_prcsn(const char *frmt, int *i, va_list list)
{
	int cr_i = *i + 1;
	int pre = -1;

	if (frmt[cr_i] != '.')
		return (pre);

	pre = 0;

	for (cr_i += 1; frmt[cr_i] != '\0'; cr_i++)
	{
		if (_is_d(frmt[cr_i]))
		{
			pre *= 10;
			pre += frmt[cr_i] - '0';
		}
		else if (frmt[cr_i] == '*')
		{
			cr_i++;
			pre = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cr_i - 1;

	return (pre);
}
