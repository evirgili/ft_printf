/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:56:14 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:09:57 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_st(t_s *st, int len, int minus)
{
	if (st->flag & FLAG_MINUS)
		st->flag ^= st->flag & FLAG_ZERO;
	st->width -= minus;
	if (st->prec != -1)
	{
		if (len > st->prec)
			st->prec = -1;
		else
			st->prec -= len;
		if (st->prec > 0)
			st->width -= st->prec;
		st->flag ^= st->flag & FLAG_ZERO;
	}
	st->width -= len;
}

void	print_part(long int d, t_s *st, int minus)
{
	if (minus && !(st->flag & FLAG_ZERO))
		write(1, "-", 1);
	if (st->prec > 0)
		ft_repeat_char('0', st->prec);
	if (!st->dot || d)
		ft_putnbr(d, 10, '0');
}

void	prtminus(long int *d, int *minus, int *len, t_s *st)
{
	*minus = 0;
	if (*d < 0 && (*d = *d * (-1)))
		*minus = 1;
	if (st->dot && !(*d))
		*len = 0;
	else
		*len = ft_len(*d, 10);
}

int		ft_type_int(long int d, t_s *st)
{
	int		minus;
	int		len;
	char	c;

	prtminus(&d, &minus, &len, st);
	mod_st(st, len, minus);
	c = st->flag & FLAG_ZERO ? '0' : ' ';
	if (st->flag & FLAG_MINUS)
	{
		print_part(d, st, minus);
		ft_repeat_char(c, st->width);
	}
	else
	{
		if (st->flag & FLAG_ZERO && minus)
			write(1, "-", 1);
		ft_repeat_char(c, st->width);
		print_part(d, st, minus);
	}
	st->prec *= st->prec >= 0;
	st->width *= st->width >= 0;
	return (len + minus + st->prec + st->width);
}
