/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:51:05 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/03 03:13:25 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void     __char__(int c, int *cot)
{
    cot += write(1, &c, 1);
}



int spat(char syb, va_list arg_list)
{
    int cot;

    cot = 0;
    if(syb == 'c')
        __char__(va_arg(arg_list, int), &cot);
    else if(syb == 's')
    {
        char *s = va_arg(arg_list, char *);
        cot += write(1, s, _length_(s));
    }
    else if(syb == 'x' || syb == 'X')
        __base__16__(va_arg(arg_list, int), syb, &cot);
    return (cot);
}
