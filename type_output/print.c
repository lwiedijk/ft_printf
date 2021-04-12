/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 15:07:46 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 17:18:44 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print(va_list *args, t_recipe rec)
{
	int	printed_len;

	printed_len = 0;
	if (rec.type == 'c')
		printed_len = print_char(args, rec);
	if (rec.type == 's')
		printed_len = print_string(args, rec);
	if (rec.type == 'd' || rec.type == 'i')
		printed_len = print_decimal(args, rec);
	if (rec.type == 'u')
		printed_len = print_decimal_unsigned(args, rec);
	if (rec.type == '%')
		printed_len = print_percent(rec);
	if (rec.type == 'x' || rec.type == 'X')
		printed_len = print_hex(args, rec);
	if (rec.type == 'p')
		printed_len = print_address(args, rec);
	return (printed_len);
}
