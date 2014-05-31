/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:58:55 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/21 02:24:58 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

size_t	ft_strlen(const char *str)
{
	size_t	cn;

	cn = -1;
	while (*(str + ++cn))
		;
	return (cn);
}
