/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:14:52 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:25:47 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *s)
{
	int			i;
	long long	num;
	int			min;

	i = 0;
	num = 0;
	min = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		min = -1 * (s[i] == '-' ? 1 : -1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if ((num * 10) < num)
			return (min < 0 ? 0 : -1);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	num = num * min;
	return (num);
}

void	print_hex(char *s, t_s *st, int minus, int d)
{
	if (minus && !(st->flag & FLAG_ZERO))
		write(1, "-", 1);
	if (st->prec > 0)
		ft_repeat_char('0', st->prec);
	if (!st->dot || d)
		write(1, s, ft_strlen(s));
}

void	hexminus(unsigned long int *d, int *minus, int *len, t_s *st)
{
	*minus = 0;
	if (st->dot && !*d)
		*len = 0;
	else
		*len = ft_len(*d, 16);
}

void	add_func(t_s *st, char *s)
{
	st->prec *= st->prec >= 0;
	st->width *= st->width >= 0;
	free(s);
}

int		ft_type_hex(unsigned long int d, t_s *st, int ind)
{
	int		minus;
	int		len;
	char	c;
	char	*s;

	s = ft_itoa(d, ind);
	len = (int)ft_strlen(s);
	minus = 0;
	hexminus(&d, &minus, &len, st);
	mod_st(st, len, minus);
	c = st->flag & FLAG_ZERO ? '0' : ' ';
	if (st->flag & FLAG_MINUS)
	{
		print_hex(s, st, minus, d);
		ft_repeat_char(c, st->width);
	}
	else
	{
		if (st->flag & FLAG_ZERO && minus)
			write(1, "-", 1);
		ft_repeat_char(c, (int)st->width);
		print_hex(s, st, minus, d);
	}
	add_func(st, s);
	return (len + minus + st->prec + st->width);
}
