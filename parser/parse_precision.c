/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:44:34 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/07 17:13:44 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	check_zero_precision(t_recipe *rec)
{
	if (rec->precision < 0)
		rec->neg_precision = rec->precision;
	if (rec->precision == 0)
		rec->precision = -1;
}

int	parse_precision(va_list *args, t_recipe *rec, const char **format)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			rec->precision = va_arg(*args, int);
			(*format)++;
			check_zero_precision(rec);
		}
		else if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
			{
				rec->precision = (rec->precision * 10) + (**format - '0');
				(*format)++;
			}
			check_zero_precision(rec);
		}
		else if (ft_isalpha(**format) && (**format != 'l' || **format != 'h'))
			rec->precision = -1;
		if (rec->neg_precision)
			rec->precision = 0;
		return (1);
	}
	return (0);
}
