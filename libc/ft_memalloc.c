/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:34:07 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:47:29 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memalloc(size_t len)
{
	void	*ret;

	if (!(ret = malloc(len)))
		return (NULL);
	ft_bzero(ret, sizeof(*ret));
	return (ret);
}
