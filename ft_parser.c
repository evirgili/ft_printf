/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:22:47 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 21:41:27 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(const char *format, int *i, t_s *st)
{
	while (format[*i])
	{
		if (format[*i] == '-')
			st->flag |= FLAG_MINUS;
		else if (format[*i] == '0')
			st->flag |= FLAG_ZERO;
		else
			break ;
		(*i)++;
	}
}

void	get_width(const char *format, int *i, va_list *ap, t_s *st)
{
	if (format[*i] == '*')
	{
		st->width = va_arg(*ap, int);
		if (st->width < 0)
		{
			st->width *= -1;
			st->flag |= FLAG_MINUS;
		}
		(*i)++;
	}
	else
	{
		st->width = ft_atoi(&format[*i]);
		while (format[*i] && ft_isdigit(format[*i]))
			(*i)++;
	}
}

void	get_prec(const char *format, int *i, va_list *ap, t_s *st)
{
	st->dot = 0;
	if (format[*i] != '.')
		return ;
	(*i)++;
	if (format[*i] == '*')
	{
		st->prec = va_arg(*ap, int);
		(*i)++;
	}
	else
	{
		st->prec = ft_atoi(&format[*i]);
		while (format[*i] && ft_isdigit(format[*i]))
			(*i)++;
	}
	st->dot = st->prec == 0;
	if (st->prec < 0)
		st->prec = -1;
}
