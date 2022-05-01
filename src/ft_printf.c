/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:12:41 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/07 20:12:28 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

static char is_specifier(char syb)
{
	if(syb == 'c' || syb == 's' || syb == 'p'
		|| syb == 'x' || syb == 'X' || syb == 'u'
		|| syb == 'd' || syb == 'i' || syb == '%')
		return (syb);
	else
		return (0);
}

int	ft_printf(const char *placeholder, ...)
{
	int		symbols;
	int		i;
	int		c;
	va_list	rest;

	i = 0;
	c = 0;
	symbols = 0;
	va_start(rest, placeholder);
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			symbols += spat(placeholder[i + 1], rest);
			i++;
		}
		else
			symbols += write(1, &placeholder[i], 1);
		i++;
	}
	va_end(rest);
	return (symbols);
}

// int main(void)
// {
// 	   printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	printf("\n");
// 	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);	
// }