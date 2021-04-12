/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <lwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 14:21:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/03/10 09:56:51 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_recipe
{
	int			minus_flag;
	int			zero_flag;
	int			space_flag;
	int			plus_flag;
	int			hash_flag;
	int			hash_len;
	int			width;
	int			precision;
	int			neg_precision;
	char		type;
	char		length;
}				t_recipe;

int				ft_printf(const char *format, ...);
int				parse(va_list *args, const char **format, t_recipe *rec);
int				parse_flag(t_recipe *rec, const char **format);
int				parse_precision(va_list *args, t_recipe *rec,
					const char **format);
int				parse_width(va_list *args, t_recipe *rec, const char **format);
int				parse_type(t_recipe *rec, const char **format);
int				parse_length(t_recipe *rec, const char **format);
void			write_padding(char padding_char, int len);
int				numlen_base_precision(long long value, int base, t_recipe rec);
int				numlen_base_precisionunsigned(unsigned long long value,
					int base, t_recipe rec);
char			*itoa_base_max(int numlen);
void			output_decimal(char *char_num, int numlen, t_recipe rec);
void			left_pads_decimal(t_recipe rec, long long num, int *numlen,
					char **converted_number);
int				padlen_decimal(t_recipe rec, int numlen, long long num);
void			check_hex_prefix(t_recipe *rec, unsigned long long int num);
char			*hexstring_highlow_case(unsigned long long num, t_recipe rec);
int				calc_return_hex(unsigned long long int num, int numlen,
					t_recipe rec);
int				print(va_list *args, t_recipe rec);
int				print_char(va_list *args, t_recipe rec);
int				print_string(va_list *args, t_recipe rec);
int				print_decimal(va_list *args, t_recipe rec);
int				print_decimal_unsigned(va_list *args, t_recipe rec);
int				print_percent(t_recipe rec);
int				print_address(va_list *args, t_recipe rec);
int				print_hex(va_list *args, t_recipe rec);
void			print_float(va_list *args, t_recipe rec);

#endif
