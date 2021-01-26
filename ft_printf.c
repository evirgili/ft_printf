/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:48:40 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/24 14:06:51 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(char type, va_list *ap, t_s *st)
{
	int	v2;

	if (type == 'c')
		v2 = ft_type_char((char)va_arg(*ap, int), st);
	else if (type == '%')
		v2 = ft_type_char('%', st);
	else if (type == 's')
		v2 = ft_type_str(va_arg(*ap, char *), st);
	else if (type == 'p')
		v2 = ft_type_pointer(va_arg(*ap, unsigned long int), st);
	else if (type == 'i' || type == 'd')
		v2 = ft_type_int(va_arg(*ap, int), st);
	else if (type == 'u')
		v2 = ft_type_uint(va_arg(*ap, unsigned int), st);
	else if (type == 'x')
		v2 = ft_type_hex(va_arg(*ap, unsigned int), st, 0);
	else if (type == 'X')
		v2 = ft_type_hex(va_arg(*ap, unsigned int), st, 1);
	else
		return (-1);
	return (v2);
}

int		ft_parser(const char *format, int *i, va_list *ap)
{
	t_s st;

	(*i)++;
	st.flag = 0;
	st.width = 0;
	st.prec = -1;
	get_flags(format, i, &st);
	get_width(format, i, ap, &st);
	get_prec(format, i, ap, &st);
	return (ft_type(format[*i], ap, &st));
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		v;
	int		pn;

	i = -1;
	v = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if ((pn = ft_parser(format, &i, &ap)) != 0)
				v += pn;
		}
		else
			v += write(1, &(format[i]), 1);
		if (!format[i])
			return (-1);
	}
	va_end(ap);
	return (v);
}
