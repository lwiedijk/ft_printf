/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 14:43:41 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 17:05:21 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>

void	check_hex_prefix(t_recipe *rec, unsigned long long int num)
{
	char	*hex_prefix;

	if (rec->hash_flag && num)
	{
		if (rec->type == 'x')
			hex_prefix = "0x";
		if (rec->type == 'X')
			hex_prefix = "0X";
		if (rec->hash_flag)
			write(1, hex_prefix, 2);
		rec->hash_flag = 0;
		rec->hash_len = 1;
	}
}

char	*hexstring_highlow_case(unsigned long long num, t_recipe rec)
{
	char	*char_number;

	if (rec.type == 'x')
		char_number = ft_itoa_base(num, 16, "0123456789abcdef");
	else
		char_number = ft_itoa_base(num, 16, "0123456789ABCDEF");
	return (char_number);
}

int	calc_return_hex(unsigned long long int num, int numlen, t_recipe rec)
{
	int	printed_len;

	printed_len = numlen;
	if (rec.precision == -1 && !num)
		return (rec.width);
	if (rec.hash_len)
	{
		printed_len += 2;
		if (rec.width >= rec.precision && rec.width > printed_len)
			return (rec.width + 2);
		if (rec.precision > printed_len)
			return (rec.precision + 2);
		return (printed_len);
	}
	if (rec.width >= rec.precision && rec.width > printed_len)
		return (rec.width);
	if (rec.precision > printed_len)
		return (rec.precision);
	return (printed_len);
}
