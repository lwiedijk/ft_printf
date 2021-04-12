/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:40:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 15:19:13 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	parse_width(va_list *args, t_recipe *rec, const char **format)
{
	int	width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(*args, int);
		if (width < 0)
		{
			rec->minus_flag = 1;
			width = width * -1;
		}
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		width = (width * 10) + (**format - '0');
		(*format)++;
	}
	rec->width = width;
	if (!width)
		return (0);
	else
		return (1);
}
