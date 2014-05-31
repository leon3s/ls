/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:28:56 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:33:24 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

void	biglen(t_file *ret, int *len)
{
	int		tg[4];

	if (ret)
	{
		if ((tg[0] = ft_nblen(ret->info.st_size)) > len[0])
			len[0] = tg[0];
		if ((tg[1] = ft_nblen(ret->info.st_nlink)) > len[1])
			len[1] = tg[1];
		if (ret->uid->pw_name)
		{
			if ((tg[2] = ft_strlen(ret->uid->pw_name)) > len[2])
				len[2] = tg[2];
		}
		if (ret->grp->gr_name)
		{
			if ((tg[3] = ft_strlen(ret->grp->gr_name)) > len[3])
				len[3] = tg[3];
		}
	}
}
