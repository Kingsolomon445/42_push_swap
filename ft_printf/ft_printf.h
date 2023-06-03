/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:24:07 by ofadahun          #+#    #+#             */
/*   Updated: 2023/04/21 12:28:14 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct t_arg
{
	va_list	args;
}	t_arg;

char	*ft_itoa_lowerhex(unsigned long n);
char	*ft_itoa_upperhex(unsigned long n);
char	*ft_itoa_unsigned(unsigned int n);
void	ft_printchar(char *padding, int ch, ssize_t *res, char flag);
int		ft_printnbr(char *padding, int n, ssize_t *res, char flag);
int		ft_printunsignednbr(char *padding, \
unsigned int n, ssize_t *res, char flag);
int		ft_plhex(char *padding, unsigned int n, \
ssize_t *res, char flag);
int		ft_puhex(char *padding, unsigned int n, \
ssize_t *res, char flag);
int		ft_printptr(char *padding, unsigned long n, ssize_t *res, char flag);
void	ft_printstr(char *padding, char *s, ssize_t *res, char flag);
void	ft_free(void *ptr);
int		ft_max(int nbr1, int nbr2);
int		ft_eval_specifier(const char *format, t_arg *arg, ssize_t *res, int *i);
int		ft_nbrlen(unsigned long num, int base);
int		ft_printf(const char *format, ...);

#endif //FT_PRINTF_H