#include "main.h"

/**
 * print_unsigned_num - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array for print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Characters printed.
 */
int print_unsigned_num(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_num_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal_notation - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Characters printed
 */
int print_octal_notation(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_num_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * hexadecimal_notation - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates flags
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Characters printed
 */
int print_hexadecimal_notation(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (hexa_number(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * hexa_upper_notation - Prints an unsigned numb in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates flags
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Characters printed
 */
int hexa_upper_notation(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * hexa_number - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to for print
 * @flags: Calculates flags
 * @flag_ch: Calculates flags
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies the size
 * @size: Specifies the size
 * Return: Characters printed
 */
int hexa_number(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
