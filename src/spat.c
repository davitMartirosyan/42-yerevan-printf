/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:51:05 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/07 20:04:55 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	spat(char syb, va_list arg_list)
{
	int		cot;
	char	*hex;

	hex = "0123456789abcdef0123456789ABCDEF";
	cot = 0;
	if (syb == 'c')
		__char__(va_arg(arg_list, int), &cot);
	else if (syb == 's')
		__string__(va_arg(arg_list, char *), &cot);
	else if (syb == 'x' || syb == 'X')
		__base__16__(va_arg(arg_list, unsigned int), syb, &cot, hex);
	else if (syb == 'd' || syb == 'i')
		__number__(va_arg(arg_list, int), &cot);
	else if (syb == 'p')
		__pointer__(va_arg(arg_list, void *), &cot, hex);
	else if (syb == 'u')
		__uint__(va_arg(arg_list, unsigned int), &cot);
	else if (syb == '%')
		__char__('%', &cot);
	return (cot);
}
