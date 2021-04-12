/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 15:02:59 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 17:13:31 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	parse_bonus_flag(t_recipe *rec, const char **format)
{
	if (**format == '+')
	{
		rec->plus_flag = 1;
		return (1);
	}
	if (**format == ' ')
	{
		rec->space_flag = 1;
		return (1);
	}
	if (**format == '#')
	{
		rec->hash_flag = 1;
		return (1);
	}
	return (0);
}

int	parse_flag(t_recipe *rec, const char **format)
{
	(*format)++;
	if (**format == '-')
	{
		rec->minus_flag = 1;
		return (1);
	}
	if (**format == '0')
	{
		rec->zero_flag = 1;
		return (1);
	}
	if (parse_bonus_flag(rec, format))
		return (1);
	return (0);
}
