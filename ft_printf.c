/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:12:41 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/03 03:15:19 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int ft_printf(const char *placeholder, ...)
{
    int symbols;
 
    symbols = 0;
    va_list rest;
    va_start(rest, placeholder);
    while(*placeholder)
    {
        if(*placeholder == '%')
        {
            symbols += spat(*(placeholder + 1), rest);
            placeholder++;
        }
        else
            symbols += write(1, *(&placeholder), 1);
        placeholder++;
    }
    va_end(rest);
    return (symbols);
}


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
		return ;
    }
	else
    {
        if(uol == 'X')
            offset = 16;
        buffer[index++] = hex[(dec % 16) + offset];
    }
	__base__16__(dec / 16, uol, cot);
}



int main(void)
{
    ft_printf("%X", 1245678);
    printf("\n%X", 1245678);
}