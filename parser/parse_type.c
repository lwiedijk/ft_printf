/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:42:35 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/02/17 17:10:46 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse_type(t_recipe *rec, const char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == '%'
		|| **format == 'n' || **format == 'f' || **format == 'g'
		|| **format == 'e')
	{
		rec->type = **format;
		(*format)++;
		return (1);
	}
	return (0);
}
