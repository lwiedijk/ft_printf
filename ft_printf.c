/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:22:37 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/09 13:00:33 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	zero_out_rec(t_recipe *rec)
{
	rec->minus_flag = 0;
	rec->zero_flag = 0;
	rec->space_flag = 0;
	rec->plus_flag = 0;
	rec->hash_flag = 0;
	rec->hash_len = 0;
	rec->width = 0;
	rec->precision = 0;
	rec->neg_precision = 0;
	rec->type = '\0';
	rec->length = '\0';
}

static int	len_till_percent(const char *print)
{
	int	len;

	len = 0;
	while (*print && *print != '%')
	{
		len++;
		print++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_recipe	rec;
	int			printed_len;
	int			return_val;

	printed_len = 0;
	va_start(args, format);
	while (*format)
	{
		zero_out_rec(&rec);
		printed_len = printed_len + len_till_percent(format);
		write(1, format, len_till_percent(format));
		format = format + len_till_percent(format);
		if (*format)
		{
			parse(&args, &format, &rec);
			return_val = print(&args, rec);
			if (return_val < 0)
				return (-1);
			printed_len = printed_len + return_val;
		}
	}
	va_end(args);
	return (printed_len);
}
