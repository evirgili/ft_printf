/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:50:30 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:24:40 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_function(char *s, t_s *st, int minus, unsigned long int d)
{
	char	c;

	c = st->flag & FLAG_ZERO ? '0' : ' ';
	if (st->flag & FLAG_MINUS)
	{
		write(1, "0x", 2);
		print_hex(s, st, minus, d);
		ft_repeat_char(c, st->width);
	}
	else
	{
		ft_repeat_char(c, (int)st->width);
		write(1, "0x", 2);
		print_hex(s, st, minus, d);
	}
	st->prec *= st->prec >= 0;
	st->width *= st->width >= 0;
	free(s);
}

int		ft_type_pointer(unsigned long int d, t_s *st)
{
	int		minus;
	int		len;
	char	c;
	char	*s;

	s = ft_itoa(d, 0);
	len = (int)ft_strlen(s);
	minus = 0;
	hexminus(&d, &minus, &len, st);
	len += 2;
	mod_st(st, len, minus);
	if (st->prec != -1)
		st->prec += 2;
	c = st->flag & FLAG_ZERO ? '0' : ' ';
	add_function(s, st, minus, d);
	return (len + minus + st->prec + st->width);
}
