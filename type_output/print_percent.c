/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_percent.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 15:13:42 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 17:06:20 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	print_percent(t_recipe rec)
{
	if (rec.width && !rec.minus_flag)
	{
		if (rec.zero_flag)
			write_padding('0', rec.width - 1);
		else
			write_padding(' ', rec.width - 1);
	}
	write(1, "%", 1);
	if (rec.width && rec.minus_flag)
		write_padding(' ', rec.width - 1);
	if (rec.width)
		return (rec.width);
	return (1);
}
