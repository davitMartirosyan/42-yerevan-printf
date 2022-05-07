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

int	ft_printf(const char *placeholder, ...)
{
	int		symbols;
	int		i;
	va_list	rest;

	i = 0;
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
