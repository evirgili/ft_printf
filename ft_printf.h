/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evirgili <evirgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:16:31 by evirgili          #+#    #+#             */
/*   Updated: 2021/01/23 22:27:54 by evirgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FLAG_MINUS 1
# define FLAG_ZERO 1 << 1

typedef struct		s_t {
	unsigned char	flag;
	int				width;
	int				prec;
	int				dot;
}					t_s;

int					ft_printf(const char *format, ...);
int					ft_atoi(const char *s);
int					ft_isdigit(int n);
int					ft_repeat_char(char c, int len);
void				get_flags(const char *format, int *i, t_s *st);
void				get_width(const char *format, int *i, va_list *ap, t_s *st);
void				get_prec(const char *format, int *i, va_list *ap, t_s *st);
int					ft_type_int(long int d, t_s *st);
int					ft_type_char(char f, t_s *st);
void				ft_putnbr(long int n, int cut, char c);
unsigned long int	ft_len(unsigned long int n, int cut);
void				print_part(long int d, t_s *st, int minus);
void				mod_st(t_s *st, int len, int minus);
int					ft_type_uint(unsigned int d, t_s *st);
int					ft_type_str(char *str, t_s *st);
char				*ft_itoa(unsigned long int n, int ind);
void				uprtminus(unsigned int *d, int *minus, int *len, t_s *st);
size_t				ft_strlen(const char *s);
int					ft_type_hex(unsigned long int d, t_s *st, int ind);
int					ft_type_pointer(unsigned long int d, t_s *st);
void				print_hex(char *s, t_s *st, int minus, int d);
void				hexminus(unsigned long int *d, int *minus,
					int *len, t_s *st);

#endif
