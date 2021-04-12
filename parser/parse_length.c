/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:53:58 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 13:53:59 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse_length(t_recipe *rec, const char **format)
{
	if (**format == 'l' || **format == 'h')
	{
		rec->length = **format;
		(*format)++;
		if (**format == 'l')
		{
			rec->length = 'L';
			(*format)++;
		}
		if (**format == 'h')
		{
			rec->length = 'H';
			(*format)++;
		}
		return (1);
	}
	return (0);
}
