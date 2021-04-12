/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_decimal.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 15:26:26 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/12 10:38:00 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <limits.h>

static long long	check_length_signed(va_list *args, t_recipe rec)
{
	long long int	num;

	if (rec.length == 'l')
		num = (long)va_arg(*args, long);
	if (rec.length == 'h')
		num = (short)va_arg(*args, int);
	if (rec.length == 'L')
		num = va_arg(*args, long long);
	if (rec.length == 'H')
		num = (char)va_arg(*args, int);
	if (!rec.length)
		num = (int)va_arg(*args, int);
	return (num);
}

static void	check_recipe(t_recipe *rec, long long num)
{
	if (rec->space_flag && rec->plus_flag)
		rec->space_flag = 0;
	if (rec->precision)
		rec->zero_flag = 0;
	if (num < 0)
	{
		rec->plus_flag = 0;
		rec->space_flag = 0;
	}
}

static int	calc_return_int(long long num, int numlen, t_recipe rec)
{
	if (rec.zero_flag && num < 0)
	{
		if (rec.width >= numlen + 1 && rec.width > rec.precision)
			return (rec.width);
	}
	if (rec.width >= numlen && rec.width > rec.precision)
		return (rec.width);
	if (rec.precision >= numlen && num >= 0)
		return (rec.precision + rec.plus_flag + rec.space_flag);
	if (rec.precision >= numlen && num < 0)
		return (rec.precision + 1);
	return (numlen + rec.plus_flag + rec.space_flag);
}

int	print_decimal(va_list *args, t_recipe rec)
{
	long long int	num;
	int				numlen;
	char			*char_number;
	char			*temp;
	int				padding_len;

	num = check_length_signed(args, rec);
	check_recipe(&rec, num);
	numlen = numlen_base_precision(num, 10, rec);
	padding_len = padlen_decimal(rec, numlen, num);
	if (num == LONG_MIN)
		char_number = itoa_base_max(numlen);
	else
		char_number = ft_itoa_base(num, 10, "0123456789");
	if (!char_number)
		return (-1);
	temp = char_number;
	left_pads_decimal(rec, num, &numlen, &char_number);
	output_decimal(char_number, numlen, rec);
	if (rec.width && rec.minus_flag)
		write_padding(' ', padding_len);
	free(temp);
	return (calc_return_int(num, numlen, rec));
}
