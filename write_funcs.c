#include "main.h"


/**
 * handle_write_char - Prints the string
 * @c: char type.
 * @bff: bff array to handle 
 * @fl:  Calculate active fl.
 * @wdt: get wdt.
 * @pre: pre specifier
 * @sz: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char bff[],
	int fl, int wdt, int pre, int sz)
{ 
	int i = 0;
	char addrp = ' ';

	UNUSED(pre);
	UNUSED(sz);

	if (fl & F_ZERO)
		addrp = '0';

	bff[i++] = c;
	bff[i] = '\0';

	if (wdt > 1)
	{
		bff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < wdt - 1; i++)
			bff[BUFF_SIZE - i - 2] = addrp;

		if (fl & F_MINUS)
			return (write(1, &bff[0], 1) +
					write(1, &bff[BUFF_SIZE - i - 1], wdt - 1));
		else
			return (write(1, &bff[BUFF_SIZE - i - 1], wdt - 1) +
					write(1, &bff[0], 1));
	}

	return (write(1, &bff[0], 1));
}


/**
 * write_number - Prints a string
 * @_negtv: Lista of arguments
 * @innd: char types.
 * @bff: bff array to handle print
 * @fl:  Calculates active fl
 * @wdt: get wdt.
 * @pre: pre specifier
 * @sz: sz specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int _negtv, int innd, char bff[],
	int fl, int wdt, int pre, int sz)
{
	int lnt = BUFF_SIZE - innd - 1;
	char addrp = ' ', ex_chrh = 0;

	UNUSED(sz);

	if ((fl & F_ZERO) && !(fl & F_MINUS))
		addrp = '0';
	if (_negtv)
		ex_chrh = '-';
	else if (fl & F_PLUS)
		ex_chrh = '+';
	else if (fl & F_SPACE)
		ex_chrh = ' ';

	return (write_num(innd, bff, fl, wdt, pre,
		lnt, addrp, ex_chrh));
}

/**
 * write_num - Write a number using a bufffer
 * @innd: inndex at which the number starts on the bff
 * @bff: bff
 * @fl: fl
 * @wdt: wdt
 * @prec: pre specifier
 * @lnt: Number lnt
 * @addrp: Pading char
 * @ex_chr: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int innd, char bff[],
	int fl, int wdt, int prec,
	int lnt, char addrp, char ex_chr)
{
	int i, addrp_start = 1;

	if (prec == 0 && innd == BUFF_SIZE - 2 && bff[innd] == '0' && wdt == 0)
		return (0); 
	if (prec == 0 && innd == BUFF_SIZE - 2 && bff[innd] == '0')
		bff[innd] = addrp = ' '; 
	if (prec > 0 && prec < lnt)
		addrp = ' ';
	while (prec > lnt)
		bff[--innd] = '0', lnt++;
	if (ex_chr != 0)
		lnt++;
	if (wdt > lnt)
	{
		for (i = 1; i < wdt - lnt + 1; i++)
			bff[i] = addrp;
		bff[i] = '\0';
		if (fl & F_MINUS && addrp == ' ')
		{
			if (ex_chr)
				bff[--innd] = ex_chr;
			return (write(1, &bff[innd], lnt) + write(1, &bff[1], i - 1));
		}
		else if (!(fl & F_MINUS) && addrp == ' ')
		{
			if (ex_chr)
				bff[--innd] = ex_chr;
			return (write(1, &bff[1], i - 1) + write(1, &bff[innd], lnt));
		}
		else if (!(fl & F_MINUS) && addrp == '0')
		{
			if (ex_chr)
				bff[--addrp_start] = ex_chr;
			return (write(1, &bff[addrp_start], i - addrp_start) +
				write(1, &bff[innd], lnt - (1 - addrp_start)));
		}
	}
	if (ex_chr)
		bff[--innd] = ex_chr;
	return (write(1, &bff[innd], lnt));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @_negtv: Number inndicating if the num is negative
 * @innd: inndex at which the number starts in the bff
 * @bff: Array of chars
 * @fl: fl specifiers
 * @wdt: wdt specifier
 * @pre: pre specifier
 * @sz: sz specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int _negtv, int innd,
	char bff[],
	int fl, int wdt, int pre, int sz)
{
	
	int lnt = BUFF_SIZE - innd - 1, i = 0;
	char addrp = ' ';

	UNUSED(_negtv);
	UNUSED(sz);

	if (pre == 0 && innd == BUFF_SIZE - 2 && bff[innd] == '0')
		return (0); 

	if (pre > 0 && pre < lnt)
		addrp = ' ';

	while (pre > lnt)
	{
		bff[--innd] = '0';
		lnt++;
	}

	if ((fl & F_ZERO) && !(fl & F_MINUS))
		addrp = '0';

	if (wdt > lnt)
	{
		for (i = 0; i < wdt - lnt; i++)
			bff[i] = addrp;

		bff[i] = '\0';

		if (fl & F_MINUS) 
		{
			return (write(1, &bff[innd], lnt) + write(1, &bff[0], i));
		}
		else 
		{
			return (write(1, &bff[0], i) + write(1, &bff[innd], lnt));
		}
	}

	return (write(1, &bff[innd], lnt));
}

/**
 * write_pointer - Write a memory address
 * @bff: Arrays of chars
 * @innd: inndex at which the number starts in the bff
 * @lnt: lnt of number
 * @wdt: Wwdt specifier
 * @fl: fl specifier
 * @addrp: Char representing the padding
 * @ex_chr: Char representing extra char
 * @addrp_start: inndex at which addrping should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char bff[], int innd, int lnt,
	int wdt, int fl, char addrp, char ex_chr, int addrp_start)
{
	int i;

	if (wdt > lnt)
	{
		for (i = 3; i < wdt - lnt + 3; i++)
			bff[i] = addrp;
		bff[i] = '\0';
		if (fl & F_MINUS && addrp == ' ')
		{
			bff[--innd] = 'x';
			bff[--innd] = '0';
			if (ex_chr)
				bff[--innd] = ex_chr;
			return (write(1, &bff[innd], lnt) + write(1, &bff[3], i - 3));
		}
		else if (!(fl & F_MINUS) && addrp == ' ')
		{
			bff[--innd] = 'x';
			bff[--innd] = '0';
			if (ex_chr)
				bff[--innd] = ex_chr;
			return (write(1, &bff[3], i - 3) + write(1, &bff[innd], lnt));
		}
		else if (!(fl & F_MINUS) && addrp == '0')
		{
			if (ex_chr)
				bff[--addrp_start] = ex_chr;
			bff[1] = '0';
			bff[2] = 'x';
			return (write(1, &bff[addrp_start], i - addrp_start) +
				write(1, &bff[innd], lnt - (1 - addrp_start) - 2));
		}
	}
	bff[--innd] = 'x';
	bff[--innd] = '0';
	if (ex_chr)
		bff[--innd] = ex_chr;
	return (write(1, &bff[innd], BUFF_SIZE - innd - 1));
}
