/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:02:44 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/04 21:05:32 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	__pointer__(void *addr, int *cot, char *hex)
{
	unsigned long long	address;
	unsigned int		i;
	char				buffer[100];

	address = (unsigned long long)addr;
	*cot += write(1, "0x", 2);
	if (address == 0)
	{
		*cot += write(1, "0", 1);
		return ;
	}
	i = 0;
	while (address)
	{
		buffer[i] = hex[address % 16];
		address /= 16;
		i++;
	}
	buffer[i] = '\0';
	__rev__(buffer, 0, _length_(buffer)-1);
	*cot += write(1, buffer, _length_(buffer));
}
