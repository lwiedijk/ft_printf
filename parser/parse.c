/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:37:02 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/02/17 17:11:39 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse(va_list *args, const char **format, t_recipe *rec)
{
	while (1)
	{
		if (parse_flag(rec, format))
			continue ;
		parse_width(args, rec, format);
		parse_precision(args, rec, format);
		parse_length(rec, format);
		parse_type(rec, format);
		break ;
	}
	if (!rec->type)
		return (-1);
	return (0);
}
