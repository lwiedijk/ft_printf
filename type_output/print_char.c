/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 15:13:23 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/12 14:11:33 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stddef.h>
#include <unistd.h>

static void	do_padding(t_recipe rec)
{
	if (rec.zero_flag)
		write_padding('0', rec.width - 1);
	else
		write_padding(' ', rec.width - 1);
}

int	print_char(va_list *args, t_recipe rec)
{
	wchar_t	c;

	if (rec.length == 'l')
		c = va_arg(*args, wchar_t);
	else
		c = (char)va_arg(*args, int);
	if (rec.width && !rec.minus_flag)
		do_padding(rec);
	write(1, &c, 1);
	if (rec.width && rec.minus_flag)
		write_padding(' ', rec.width - 1);
	if (rec.width)
		return (rec.width);
	else
		return (1);
}
