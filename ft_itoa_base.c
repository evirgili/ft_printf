/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:33:46 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/24 18:07:48 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_null(long long n)
{
	char				*null;

	null = malloc(sizeof(char) + 1);
	null[0] = '0' + n;
	null[1] = '\0';
	return (null);
}

static long long int	ft_length(long long int n)
{
	long long int		len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char				*ft_num(char *num, long long int l, long long int p,
						char *base)
{
	long long int	i;

	i = 0;
	num[l] = '\0';
	i = 1;
	while (p > 0)
	{
		num[l - i] = base[p % 16];
		p = p / 16;
		i++;
	}
	return (num);
}

char					*ft_itoa(unsigned long int n, int ind)
{
	char				*num;
	long long int		l;
	long long int		p;

	p = n;
	if (p == 0)
		return (ft_null(p));
	if (n < 0)
		n *= -1;
	l = ft_length(p);
	if (!(num = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	num[l] = '\0';
	return (ind ? ft_num(num, l, p, "0123456789ABCDEF") :
			ft_num(num, l, p, "0123456789abcdef"));
}
