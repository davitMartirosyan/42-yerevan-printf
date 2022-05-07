/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __number__.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:58:56 by dmartiro          #+#    #+#             */
/*   Updated: 2022/05/07 20:02:52 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	__number__(int dec, int *cot)
{
	unsigned int	h;

	h = 0;
	if (dec >= 0)
		h = dec;
	if (dec < 0)
	{
		__char__('-', cot);
		h = dec * (-1);
	}
	if (h > 9)
		__number__((h / 10), cot);
	__char__((h % 10) + '0', cot);
}

void	__uint__(unsigned int _uint, int *cot)
{
	if (_uint > 9)
		__uint__((_uint / 10), cot);
	__char__((_uint % 10) + '0', cot);
}
