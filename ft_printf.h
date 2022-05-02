/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:10:48 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/03 03:35:04 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int     ft_printf(const char *, ...);
int     spat(char, va_list);
size_t  _length_(char *);
void    __char__(int, int *);
void    __string__(char *, int *);
int     __address__(void *);
int     __nbr__(int);
int     __nbr__unsigned__(unsigned int);
void	__base__16__(unsigned int, char, int *);
void __rev__(char *, int, unsigned int);
char	ft_to_upper(char);


#endif