/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 06:24:31 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 16:33:49 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	print_hash(t_hash *opt, char mask, int *len)
{
	int	cn;
	int	incr;

	incr = ((OPTION_R(mask)) ? -1 : 1);
	cn = ((OPTION_R(mask)) ? 256 : -1);
	if (opt->content)
	{
		if (OPTION_A(mask) || *opt->content->name != '.')
		{
			if (OPTION_L(mask))
				print_l(opt, len);
			write(1, opt->content->name, opt->content->len);
			if (OPTION_L(mask))
				if (S_ISLNK(opt->content->info.st_mode))
					print_link(opt);
			write(1, (OPTION_RR(mask) || OPTION_L(mask)) ? "\n" : "\t", 1);
		}
	}
	while ((cn += incr) < 256 && cn >= 0)
	{
		if (*(opt->hash + cn))
			if (!(print_hash(*(opt->hash + cn), mask, len)))
				return (0);
	}
	return (1);
}

char	print_thash(t_thash *topt, char mask, int *len)
{
	int	cn;
	int	incr;

	incr = ((OPTION_R(mask)) ? 1 : -1);
	cn = ((OPTION_R(mask)) ? -1 : 256);
	if (topt->content)
		print_hash(topt->content, mask, len);
	while ((cn += incr) < 256 && cn >= 0)
	{
		if (*(topt->hash + cn))
			print_thash(*(topt->hash + cn), mask, len);
	}
	return (1);
}
