/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_address.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 17:13:23 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/12 15:17:40 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int static	do_precision(t_recipe rec, int len, char *address_string)
{
	if (rec.width && rec.width > rec.precision && !rec.minus_flag)
		write_padding(' ', rec.width - rec.precision - 2);
	write(1, "0x", 2);
	write_padding('0', rec.precision - len + 2);
	write(1, address_string, len - 2);
	if (rec.width && rec.minus_flag && rec.width > rec.precision)
		write_padding(' ', rec.width - rec.precision - 2);
	free(address_string);
	if (rec.width && rec.width >= rec.precision)
		return (rec.width);
	if (rec.precision >= len)
		return (rec.precision + 2);
	return (len);
}

int	print_address(va_list *args, t_recipe rec)
{
	unsigned long long	address_num;
	char				*address_str;
	int					len;

	address_num = va_arg(*args, unsigned long long);
	address_str = ft_itoa_base(address_num, 16, "0123456789abcdef");
	if (!address_str)
		return (-1);
	len = ft_strlen(address_str) + 2;
	if (rec.precision > len - 2)
		return (do_precision(rec, len, address_str));
	if (rec.precision == -1 && address_num == 0)
		len = 2;
	if (rec.width && !rec.minus_flag && !rec.zero_flag)
		write_padding(' ', rec.width - len);
	write(1, "0x", 2);
	if (rec.width && !rec.minus_flag && rec.zero_flag)
		write_padding('0', rec.width - len);
	write(1, address_str, len - 2);
	if (rec.width && rec.minus_flag)
		write_padding(' ', rec.width - len);
	free(address_str);
	if (rec.width && rec.width >= len)
		return (rec.width);
	return (len);
}
