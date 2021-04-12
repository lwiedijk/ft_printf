/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_output_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 14:14:41 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/10 09:58:01 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	numlen_base_precision(long long value, int base, t_recipe rec)
{
	int	len;

	len = 0;
	if (rec.precision == -1 && !value)
		return (0);
	if (value < 0)
	{
		value = value * -1;
		len++;
	}
	if (value == 0)
		len++;
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

int	numlen_base_precisionunsigned(unsigned long long value,
int base, t_recipe rec)
{
	int	len;

	len = 0;
	if (rec.precision == -1 && !value)
		return (0);
	if (value == 0)
		len++;
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

void	write_padding(char padding_char, int len)
{
	while (len > 0)
	{
		write(1, &padding_char, 1);
		len--;
	}
}
