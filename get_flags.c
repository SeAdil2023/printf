nclude "main.h"

/**
 * _flag_gt - Calculates active flags
 * @frmt: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int _flag_gt(const char *frmt, int *i)
{
	
	int j, cr_i;
	int flag = 0;
	const char flg_char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_ary[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cr_i = *i + 1; frmt[cr_i] != '\0'; cr_i++)
	{
		for (j = 0; flg_char[j] != '\0'; j++)
			if (frmt[cr_i] == flg_char[j])
			{
				flag |= flag_ary[j];
				break;
			}

		if (flg_char[j] == 0)
			break;
	}

	*i = cr_i - 1;

	return (flag);
}
