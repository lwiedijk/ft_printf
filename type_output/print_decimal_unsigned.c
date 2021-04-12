/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_decimal_unsigned.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 12:58:19 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/10 09:54:14 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

static unsigned long long	check_length_unsigned(va_list *args, t_recipe rec)
{
	unsigned long long	num;

	if (rec.length == 'l')
		num = (unsigned long)va_arg(*args, unsigned long);
	if (rec.length == 'h')
		num = (unsigned short)va_arg(*args, unsigned int);
	if (rec.length == 'L')
		num = va_arg(*args, unsigned long long);
	if (rec.length == 'H')
		num = (unsigned char)va_arg(*args, unsigned int);
	if (!rec.length)
		num = (unsigned int)va_arg(*args, unsigned int);
	return (num);
}

static void	check_recipe_unsigned(t_recipe *rec)
{
	if (rec->space_flag)
		rec->space_flag = 0;
	if (rec->plus_flag)
		rec->plus_flag = 0;
	if (rec->precision)
		rec->zero_flag = 0;
}

static int	calc_return_unsigned(int numlen, t_recipe rec)
{
	if (rec.width >= numlen && rec.width > rec.precision)
		return (rec.width);
	if (rec.precision >= numlen)
		return (rec.precision);
	return (numlen);
}

int	print_decimal_unsigned(va_list *args, t_recipe rec)
{
	unsigned long long int	num;
	int						numlen;
	char					*char_number;
	char					*temp;
	int						padding_len;

	num = check_length_unsigned(args, rec);
	check_recipe_unsigned(&rec);
	numlen = numlen_base_precisionunsigned(num, 10, rec);
	padding_len = padlen_decimal(rec, numlen, num);
	char_number = ft_itoa_base_unsigned(num, 10, "0123456789");
	if (!char_number)
		return (-1);
	temp = char_number;
	left_pads_decimal(rec, num, &numlen, &char_number);
	output_decimal(char_number, numlen, rec);
	if (rec.width && rec.minus_flag)
		write_padding(' ', padding_len);
	free(temp);
	return (calc_return_unsigned(numlen, rec));
}
