/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:01:02 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:18:10 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_char(char f, t_s *st)
{
	char	c;

	if (st->flag & FLAG_ZERO && !(st->flag & FLAG_MINUS))
		c = '0';
	else
		c = ' ';
	if (!(st->flag &= FLAG_MINUS))
		ft_repeat_char(c, st->width - 1);
	write(1, &f, 1);
	if ((st->flag &= FLAG_MINUS))
		ft_repeat_char(c, st->width - 1);
	return (st->width > 0 ? st->width : 1);
}
