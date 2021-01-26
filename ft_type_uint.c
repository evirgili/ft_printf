/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:06:32 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:08:36 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uprtminus(unsigned int *d, int *minus, int *len, t_s *st)
{
	*minus = 0;
	if (st->dot && !*d)
		*len = 0;
	else
		*len = ft_len(*d, 10);
}

int		ft_type_uint(unsigned int d, t_s *st)
{
	int		minus;
	int		len;
	char	c;

	uprtminus(&d, &minus, &len, st);
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
