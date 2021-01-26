/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:05:05 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/22 18:03:05 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_str(size_t len, t_s *st)
{
	if (st->flag & FLAG_MINUS)
		st->flag ^= st->flag & FLAG_ZERO;
	if (st->prec == -1)
		st->prec = len;
	if (st->prec > (int)len)
		st->prec = len;
	st->width -= st->prec;
}

void	print_str(char *str, t_s *st)
{
	if (str)
		write(1, str, st->prec);
	else
		write(1, "(null)", st->prec);
}

int		ft_type_str(char *str, t_s *st)
{
	char	c;

	mod_str(ft_strlen(str), st);
	c = st->flag & FLAG_ZERO ? '0' : ' ';
	if (st->flag & FLAG_MINUS)
	{
		print_str(str, st);
		ft_repeat_char(c, st->width);
	}
	else
	{
		ft_repeat_char(c, st->width);
		print_str(str, st);
	}
	if (st->width < 0)
		st->width = 0;
	return (st->width + st->prec);
}
