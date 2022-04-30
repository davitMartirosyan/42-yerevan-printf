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

void __pointer__(void *addr, int *cot)
{
    char hex[] = "0123456789abcdef";
    unsigned long long address;
    unsigned int i;
    char buffer[100];

    address = (unsigned long long)addr;
    *cot += write(1, "0x", 2);
    if(address == 0)
    {
        *cot += write(1, "0", 1);
        return ;
    }
    i = 0;
    while(address)
    {
        buffer[i] = hex[address % 16];
        address /= 16;
        i++;
    }
    buffer[i] = '\0';
    __rev__(buffer, 0, _length_(buffer)-1);
    *cot += write(1, buffer, _length_(buffer));
}

int main(void)
{
    char a = 'a';
    char *c = &a;
    int s = 0;
    __pointer__(c, &s);
    printf("\n");
    printf("%p\n", c);
}


