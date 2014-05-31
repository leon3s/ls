/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 06:39:07 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 16:22:55 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	recur(t_hash *opt, char mask)
{
	int		cn;
	int		incr;

	incr = ((OPTION_R(mask)) ? -1 : 1);
	cn = ((OPTION_R(mask)) ? 256 : -1);
	if (opt->content)
	{
		if ((S_ISDIR(opt->content->info.st_mode)
					&& (!(S_ISLNK(opt->content->info.st_mode))))
				&& ((is_hidden_file(opt->content->name))))
		{
			write(1, "\n", 1);
			if (!(load_dir(opt->content->src, mask, 0)))
				return (0);
		}
	}
	while ((cn += incr) < 256 && cn >= 0)
	{
		if (*(opt->hash + cn))
			if (!(recur(*(opt->hash + cn), mask)))
				return (0);
	}
	return (1);
}

char	recur_t(t_thash *topt, char mask)
{
	int	cn;
	int	incr;

	incr = ((OPTION_R(mask)) ? 1 : -1);
	cn = ((OPTION_R(mask)) ? -1 : 256);
	if (topt->content)
		recur(topt->content, mask);
	while ((cn += incr) < 256 && cn >= 0)
	{
		if (*(topt->hash + cn))
			recur_t(*(topt->hash + cn), mask);
	}
	return (1);
}
