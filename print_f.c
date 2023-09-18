#include "main.h"

int _printf(const char *format, ...)
{
	int print_char = 0;

	va_list loa;

	if (format == NULL)
	{
		return (-1);
	}
	
	va_start(loa, format);

	while(*format){
		if (*format != '%')
		{
			write(1, format, 1);
			print_char++;
		}
		else
		{
			format++;
			
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				print_char++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(loa, int);
				write(1, &c, 1);
				print_char++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(loa, char*);
				size_t len = strlen(str);
				write(1, &str, len);
				print_char++;
			}
		}
		format++;
	}
	va_end(loa);

	return (print_char);
}
