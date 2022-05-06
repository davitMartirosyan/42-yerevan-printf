/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:53:09 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/06 20:34:30 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	_length_(char *placeholder)
{
	size_t  i;

	i = 0;
	while (*placeholder++)
		i++;
	return (i);
}

void	__rev__(char *hex, int at, int len)
{
	char	t;

	while (at < len)
	{
		t = hex[at];
		hex[at] = hex[len];
		hex[len] = t;
		at++;
		len--;
	}
}

void	__char__(int c, int *cot)
{
	*cot += write(1, &c, 1);
}

void	__string__(char *string, int *cot)
{
	if(!string)
		*cot += write(1, "(null)", 6);
	else
		*cot += write(1, string, _length_(string));
}
