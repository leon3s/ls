/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:58:46 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:58:47 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_strdup(char *str)
{
	size_t	cn;
	char	*new;

	cn = ft_strlen(str);
	if (!(new = malloc(sizeof(*new) * (cn + 1))))
		return (NULL);
	cn = -1;
	while (*(str + ++cn))
		*(new + cn) = *(str + cn);
	*(new + cn) = 0;
	return (new);
}
