#include "main.h"

/**
 * _sz_get - Calculates the size to cast the argument
 * @frmt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int _sz_get(const char *frmt, int *i)
{
	int cr_i = *i + 1;
	int sz = 0;

	if (frmt[cr_i] == 'l')
		sz = S_LONG;
	else if (frmt[cr_i] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = cr_i - 1;
	else
		*i = cr_i;

	return (sz);
}
