/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:03:33 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:25:40 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int					ft_repeat_char(char c, int len)
{
	int l;

	if (len < 0)
		return (0);
	l = -1;
	while (++l < len)
		write(1, &c, 1);
	return (len);
}

unsigned long int	ft_len(unsigned long int n, int cut)
{
	unsigned long int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / cut;
		len++;
	}
	return (len);
}

void				ft_putnbr(long int n, int cut, char c)
{
	char j;

	j = n % cut + c;
	if (n / 10)
	{
		ft_putnbr(n / 10, cut, c);
		write(1, &j, 1);
	}
	else
		write(1, &j, 1);
}

size_t				ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (s == NULL)
		return (6);
	while (s[len])
		len++;
	return (len);
}
