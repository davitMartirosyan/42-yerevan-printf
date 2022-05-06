/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __base__16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:59:39 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/06 21:12:07 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	__base__16__(unsigned int dec, char uol, int *cot, char *hex)
{
	int	offset;
	int	index;
	char buffer[100];
	
	offset = 0;
	if(dec == 0)
	{
		*cot += write(1, "0", 1);
		return ;
	}
	if(uol == 'X')
		offset = 16;
	while(dec != 0)
	{
		buffer[index] = hex[(dec % 16) + offset];
		dec /= 16;
		index++;
	}
	buffer[index] = '\0';
	__rev__(buffer, 0, _length_(buffer) - 1);
	*cot += write(1, buffer, _length_(buffer));
	
}



// static int	index = 0;
// 	int			offset;
// 	static char	buffer[100];

// 	offset = 0;
// 	if (dec == 0)
// 	{
// 		__rev__(buffer, 0, _length_(buffer) - 1);
// 		*cot += write (1, buffer, _length_(buffer));
// 		buffer[0] = 0;
// 		index = 0;
// 		return ;
// 	}
// 	if (uol == 'X')
// 		offset = 16;
// 	buffer[index] = hex[(dec % 16) + offset];
// 	index++;
// 	__base__16__(dec / 16, uol, cot, hex);
