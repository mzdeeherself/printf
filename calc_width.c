#include "main.h"

/**
* calc_width - Calc the width for printing.
* @format: Format string to print the arguments.
* @i: arguments list to be printed
* @list: arguments list.
* Return: width.
*/

int calc_width(const char *format, int *i, va_list list)
{
	int num_i;
	int width = 0;

	for (num_i = *i + 1; format[num_i] != '\0'; num_i++)
	{
		if (_digit(format[num_i]))
		{
			width *= 10;
			width += format[num_i] - '0';
		}
		else if (format[num_i] == '*')
		{
			num_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = num_i - 1;

	return (width);
}
