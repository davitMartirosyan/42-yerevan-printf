/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:12:41 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/03 07:46:10 by dmartiro         ###   ########.fr       */
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



int main(void)
{
    char a = 'c';
    char *d = &a;
    unsigned long int dd;
    dd = (long int)d;
    char z[] = "0123456789abcdef";
    char buff[50];
    int i = 0;
    while(dd != 0)
    {
        buff[i] = z[dd%16];
        printf("%lu ||| %c\n", dd % 16, z[dd%16]);
        dd /= 16;
        i++;
    }
    int x = 0;
    buff[i] = 0;
    __rev__(buff, 0, _length_(buff)-1);
    __string__("0x", &x);
    __string__(buff, &x);
    printf("\n%p\n", d);
    // printf("%p\n", d);
}


