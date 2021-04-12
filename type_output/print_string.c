/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 15:01:10 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/11 20:19:49 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>

static void	do_padding(char **s, t_recipe *rec)
{
	if (rec->zero_flag)
		write_padding('0', rec->width - ft_strlen(*s));
	else
		write_padding(' ', rec->width - ft_strlen(*s));
	write(1, *s, ft_strlen(*s));
}

static void	do_width_and_no_minusflag(char **s, t_recipe *rec)
{
	if (rec->precision)
	{
		if (rec->precision == -1)
			write_padding(' ', rec->width);
		else
		{
			if (rec->precision > (int)ft_strlen(*s))
			{
				write_padding(' ', rec->width - ft_strlen(*s));
				write(1, *s, ft_strlen(*s));
			}
			else if (rec->precision <= (int)ft_strlen(*s))
			{
				write_padding(' ', rec->width - rec->precision);
				write(1, *s, rec->precision);
			}
		}
	}
	else
		do_padding(s, rec);
}

static void	do_width_and_yes_minusflag(char **s, t_recipe *rec)
{
	if (rec->precision)
	{
		if (rec->precision == -1)
			write_padding(' ', rec->width);
		else
		{
			if (rec->precision > (int)ft_strlen(*s))
			{
				write(1, *s, ft_strlen(*s));
				write_padding(' ', rec->width - ft_strlen(*s));
			}
			else if (rec->precision <= (int)ft_strlen(*s))
			{
				write(1, *s, rec->precision);
				write_padding(' ', rec->width - rec->precision);
			}
		}
	}
	else
	{
		write(1, *s, ft_strlen(*s));
		write_padding(' ', rec->width - ft_strlen(*s));
	}
}

static void	do_precision_and_no_width(char **s, t_recipe *rec)
{
	if (rec->precision == -1)
		return ;
	else if (rec->precision <= (int)ft_strlen(*s))
		write(1, *s, rec->precision);
	else if (rec->precision > (int)ft_strlen(*s))
		write(1, *s, ft_strlen(*s));
}

int	print_string(va_list *args, t_recipe rec)
{
	char	*s;

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	if (rec.width && !rec.minus_flag)
		do_width_and_no_minusflag(&s, &rec);
	else if (rec.width && rec.minus_flag)
		do_width_and_yes_minusflag(&s, &rec);
	else if (rec.precision && !rec.width)
		do_precision_and_no_width(&s, &rec);
	else
		write(1, s, ft_strlen(s));
	if (rec.precision && rec.precision < (int)ft_strlen(s))
	{
		if (rec.precision == -1)
			return (rec.width);
		if (rec.width && rec.width >= rec.precision)
			return (rec.width);
		return (rec.precision);
	}
	if (rec.width && rec.width >= (int)ft_strlen(s))
		return (rec.width);
	return (ft_strlen(s));
}
