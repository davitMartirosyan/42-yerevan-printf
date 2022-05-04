/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:59:39 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/04 21:11:03 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	__base__16__(unsigned int dec, char uol, int *cot, char *hex)
{
	static int	index = 0;
	int			offset;
	static char	buffer[100];

	offset = 0;
	if (dec == 0)
	{
		__rev__(buffer, 0, _length_(buffer) - 1);
		*cot += write (1, buffer, index);
		buffer[0] = 0;
		index = 0;
		return ;
	}
	else
	{
		if (uol == 'X')
			offset = 16;
		buffer[index] = hex[(dec % 16) + offset];
	}
	index++;
	__base__16__(dec / 16, uol, cot, hex);
}
