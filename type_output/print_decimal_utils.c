/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_decimal_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 14:24:07 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/12 14:27:36 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	padlen_decimal(t_recipe rec, int numlen, long long num)
{
	int	padding_len;

	padding_len = rec.width;
	if (rec.precision && rec.precision >= numlen)
	{
		padding_len -= (rec.precision + rec.space_flag + rec.plus_flag);
		if (num < 0)
			padding_len--;
	}
	else
		padding_len -= (numlen + rec.plus_flag + rec.space_flag);
	return (padding_len);
}

void	left_pads_decimal(t_recipe rec, long long num, int *numlen,
char **converted_number)
{
	int	padding_len;

	padding_len = padlen_decimal(rec, *numlen, num);
	if (rec.width && !rec.minus_flag)
	{
		if (rec.zero_flag && rec.width >= *numlen)
		{
			if (num < 0)
			{
				write(1, "-", 1);
				(*converted_number)++;
				(*numlen)--;
			}
			if (rec.plus_flag)
				write(1, "+", 1);
			if (rec.space_flag)
				write(1, " ", 1);
			write_padding('0', padding_len);
		}
		else
			write_padding(' ', padding_len);
	}
}

void	output_decimal(char *char_num, int numlen, t_recipe rec)
{
	if (*char_num == '-')
	{
		write(1, "-", 1);
		numlen--;
		char_num++;
	}
	if (rec.plus_flag && !rec.zero_flag)
	{
		write(1, "+", 1);
	}
	if (rec.space_flag && !rec.zero_flag)
		write(1, " ", 1);
	if (rec.precision)
		write_padding('0', rec.precision - numlen);
	write(1, char_num, numlen);
}

char	*itoa_base_max(int numlen)
{
	int		l;
	char	*output;

	l = numlen;
	output = (char *)malloc(sizeof(char) * l + 1);
	ft_strcpy(output, "-9223372036854775808");
	return (output);
}
