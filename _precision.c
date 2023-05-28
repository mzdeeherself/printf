#include "main.h"

/**
* _precision - Calculates the precision for printing.
* @format: Format string to print the arguments
* @i: argument list to be printed.
* @list:  arguments list.
* Return: Precision.
*/

int _precision(const char *format, int *i, va_list list)
{
	int odds_i = *i + 1;
	int precision = -1;

	if (format[odds_i] != '.')
		return (precision);

	precision = 0;

	for (odds_i += 1; format[odds_i] != '\0'; odds_i++)
	{
		if (_digit(format[odds_i]))
		{
			precision *= 10;
			precision += format[odds_i] - '0';
		}
		else if (format[odds_i] == '*')
		{
			odds_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = odds_i - 1;

	return (precision);
}
