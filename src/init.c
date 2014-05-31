/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:37:56 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:39:21 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

void	init_lens(int *len)
{
	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
}

int		*init_value(int *len, t_thash *topt, t_hash *opt)
{
	if (!(len = malloc(sizeof(*len) * 5)))
		return (0);
	init_lens(len);
	ft_bzero(opt, sizeof(*opt));
	ft_bzero(topt, sizeof(*topt));
	return (len);
}
