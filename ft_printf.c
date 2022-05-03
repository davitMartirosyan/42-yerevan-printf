/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:12:41 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/03 07:03:36 by dmartiro         ###   ########.fr       */
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

void __number__(int dec, int *cot)
{
    
}

int main(void)
{
    ft_printf("%c\n", 'c');
    ft_printf("%s\n", "hello world");
    ft_printf("%x\n", 255);
    ft_printf("%X\n", 255);
}


