/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:51:05 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/03 03:45:22 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	__base__16__(unsigned int dec, char uol, int *cot)
{
    static int  index = 0;
	char	*hex;
    int     offset;
    static char buffer[100];

    offset = 0;
    hex  = "0123456789abcdef0123456789ABCDEF";
	if (dec == 0)
    {
        __rev__(buffer, 0, _length_(buffer)-1);
        *cot += write(1, buffer, index);
        buffer[0] = 0;
        index = 0;
		return ;
    }
	else
    {
        if(uol == 'X')
            offset = 16;
        buffer[index] = hex[(dec % 16) + offset];
    }
    index++;
	__base__16__(dec / 16, uol, cot);
}

int spat(char syb, va_list arg_list)
{
    int cot;

    cot = 0;
    if(syb == 'c')
        __char__(va_arg(arg_list, int), &cot);
    else if(syb == 's')
        __string__(va_arg(arg_list, char *), &cot);
    else if(syb == 'x' || syb == 'X')
        __base__16__(va_arg(arg_list, int), syb, &cot);
    return (cot);
}
