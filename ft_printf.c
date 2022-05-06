/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:12:41 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/05 20:14:29 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *placeholder, ...)
{
	int symbols;
	
	symbols = 0;
	va_list rest;
	va_start(rest, placeholder);
	while (*placeholder)
	{
		if (*placeholder == '%')
		{
			placeholder++;
			symbols += spat(*placeholder, rest);
		}
		else
			symbols += write(1, *(&placeholder), 1);
		placeholder++;
	}
	va_end(rest);
	return (symbols);
}
