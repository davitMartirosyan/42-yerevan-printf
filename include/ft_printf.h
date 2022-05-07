/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:10:48 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/07 20:11:37 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *placeholder, ...);
int		spat(char syb, va_list list);
size_t	_length_(char *str);
void	__char__(int c, int *cot);
void	__string__(char *str, int *cot);
void	__pointer__(void *tohexh, int *cot, char *phex);
void	__number__(int n, int *cot);
void	__uint__(unsigned int un, int *cot);
void	__base__16__(unsigned int un, char uol, int *cot, char *xhex);
void	__rev__(char *buffer, int start, int len);

#endif
