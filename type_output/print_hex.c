/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 15:26:13 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/02/14 15:26:13 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static unsigned long long int	check_length_hex(va_list *args, t_recipe rec)
{
	unsigned long long int	num;

	if (rec.length == 'l')
		num = (unsigned long)va_arg(*args, long);
	if (rec.length == 'h')
		num = (unsigned short)va_arg(*args, int);
	if (rec.length == 'L')
		num = va_arg(*args, long long);
	if (rec.length == 'H')
		num = (unsigned char)va_arg(*args, int);
	if (!rec.length)
		num = (unsigned int)va_arg(*args, int);
	return (num);
}

static void	check_left_pads(int numlen, t_recipe rec)
{
	if (rec.width && !rec.minus_flag && !rec.precision)
	{
		if (rec.zero_flag)
			write_padding('0', rec.width - numlen);
		else
			write_padding(' ', rec.width - numlen);
	}
	if (rec.width && !rec.minus_flag && rec.precision)
	{
		if (rec.precision == -1)
			write_padding(' ', rec.width - numlen);
		if (rec.precision < numlen && rec.precision > 0)
			write_padding(' ', rec.width - numlen);
		if (rec.precision >= numlen && rec.precision > 0)
			write_padding(' ', rec.width - rec.precision);
	}
}

static void	check_precision(int numlen, t_recipe rec)
{
	if (rec.precision)
	{
		if (numlen < rec.precision)
			write_padding('0', rec.precision - numlen);
	}
}

static void	check_right_pads(int numlen, t_recipe rec)
{
	if (rec.width && rec.minus_flag && !rec.precision)
		write_padding(' ', rec.width - numlen);
	if (rec.width && rec.minus_flag && rec.precision)
	{
		if (rec.precision == -1)
			write_padding(' ', rec.width - numlen);
		if (rec.precision <= numlen && rec.precision > 0)
			write_padding(' ', rec.width - numlen);
		if (rec.precision > numlen && rec.precision > 0)
			write_padding(' ', rec.width - rec.precision);
	}
}

int	print_hex(va_list *args, t_recipe rec)
{
	unsigned long long int	num;
	int						numlen;
	char					*char_number;

	if (rec.precision)
		rec.zero_flag = 0;
	num = check_length_hex(args, rec);
	numlen = numlen_base_precision(num, 16, rec);
	if (rec.hash_flag && num)
		rec.width -= 2;
	char_number = hexstring_highlow_case(num, rec);
	if (!char_number)
		return (-1);
	if (rec.zero_flag)
		check_hex_prefix(&rec, num);
	check_left_pads(numlen, rec);
	check_hex_prefix(&rec, num);
	check_precision(numlen, rec);
	write(1, char_number, numlen);
	check_right_pads(numlen, rec);
	free(char_number);
	return (calc_return_hex(num, numlen, rec));
}
