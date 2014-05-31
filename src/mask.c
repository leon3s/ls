/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 03:44:38 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 06:42:25 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	mask_arg(char **av, char *options)
{
	size_t	count;
	char	mask;

	mask = 0;
	count = -1;
	while (*(av + ++count))
	{
		if (*(*(av + count)) == '-')
			mask |= ft_mask(*(av + count) + 1, options);
	}
	if (mask == -1)
	{
		ft_error("Bads options\n");
		return (-1);
	}
	return (mask);
}

char	ft_mask(char *str, const char *ref)
{
	char ret;
	char mod;
	char count;
	char counter;

	ret = -1;
	count = -1;
	while (*(str + ++count))
	{
		if (ret == -1)
			ret = 0;
		counter = -1;
		mod = 1;
		while (*(ref + ++counter) && *(ref + counter) != *(str + count))
			mod *= 2;
		if (!(*(ref + counter)))
			return (-1);
		ret |= mod;
	}
	return (ret);
}
