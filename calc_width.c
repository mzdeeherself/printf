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
	int num _i;
	int width = 0;

	for (num _i = *i + 1; format[num _i] != '\0'; num _i++)
	{
		if (_digit(format[num _i]))
		{
			width *= 10;
			width += format[num _i] - '0';
		}
		else if (format[num _i] == '*')
		{
			num _i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = num _i - 1;

	return (width);
}
