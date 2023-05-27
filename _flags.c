#include "main.h"

/**
* _flags - Calculate flags
* @format: Format string to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int _flags(const char *format, int *i)
{
	int j, odds_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (odds_i = *i + 1; format[odds_i] != '\0'; odd_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[odds_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = odd_i - 1;

	return (flags);
}
