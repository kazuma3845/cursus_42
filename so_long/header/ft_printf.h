/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:08:18 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/15 10:15:17 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct c_num
{
	int	c;
}	t_num;

void	ft_putchar(char c, t_num *r);
void	ft_putstr(char *c, t_num *r);
void	ft_putnbr(int n, t_num *c);
void	ft_putnbru(long int n, t_num *c);
void	ft_puthex(long int string, t_num *c, char *str);
void	ft_puthex2(long int i, t_num *c, char *str);
void	ft_real(char *buffer, t_num *c);
void	ft_putptr(void *replace, t_num *c);
char	*ft_impr(char *str, int replace, void *string, t_num *c);
int		ft_finds(const char *ltr);
int		ft_findp(const char *ltr);
int		ft_printf(const char *str, ...);

#endif