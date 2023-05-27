#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Arguments to be printed.
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int odds_i = *i + 1;
	int size = 0;

	if (format[odds_i] == 'l')
		size = S_LONG;
	else if (format[odds_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = odds_i - 1;
	else
		*i = odds_i;

	return (size);
}
