#include "main.h"
/**
 * _print_handle - Prints an argument based on its type
 * @frmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @iinnd: iinnd.
 * @buffer: Buffer array to handle print.
 * @flg: Calculates active flags
 * @width: get width.
 * @pre: Precision specification
 * @sz: Size specifier
 * Return: 1 or 2;
 */
int _print_handle(const char *frmt, int *iinnd, va_list list, char buffer[],
	int flg, int width, int pre, int sz)
{
	int i, len_nknwn = 0, prntd_c = -1;
	frmt_t frmt_types[] = {
		{'c', print_the_chr}, {'s', str_prnt}, {'%', prcnt_prnt},
		{'i', integer_print}, {'d', integer_print}, {'b', bnar_prnt},
		{'u', nsignd_prnt}, {'o', _octlprnt}, {'x', hexa_prnt},
		{'X', prnthexa_up}, {'p', prnt_ptr}, {'S', prnt_n_prntbl},
		{'r', _rev_prnt}, {'R', prnt_rot13_str}, {'\0', NULL}
	};
	for (i = 0; frmt_types[i].frmt != '\0'; i++)
		if (frmt[*iinnd] == frmt_types[i].frmt)
			return (frmt_types[i].fn(list, buffer, flg, width, pre, sz));

	if (frmt_types[i].frmt == '\0')
	{
		if (frmt[*iinnd] == '\0')
			return (-1);
		len_nknwn += write(1, "%%", 1);
		if (frmt[*iinnd - 1] == ' ')
			len_nknwn += write(1, " ", 1);
		else if (width)
		{
			--(*iinnd);
			while (frmt[*iinnd] != ' ' && frmt[*iinnd] != '%')
				--(*iinnd);
			if (frmt[*iinnd] == ' ')
				--(*iinnd);
			return (1);
		}
		len_nknwn += write(1, &frmt[*iinnd], 1);
		return (len_nknwn);
	}
	return (prntd_c);
}
