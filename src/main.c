/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 03:44:29 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 19:53:23 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

int		main(int UN ac, char **av)
{
	int		count;
	char	mask;
	int		ret;

	ret = 0;
	count = 0;
	if ((mask = mask_arg(av, OPTS)) == -1)
		return (0);
	while (*(av + ++count))
	{
		if ((*(*(av + count)) != '-'))
		{
			++ret;
			if (!(load_dir(*(av + count), mask, ret)))
				return (0);
			else
				write(1, "\n", 1);
		}
	}
	if (ret == 0)
		load_dir(".", mask, ret);
	if (!(OPTION_L(mask)) && (!OPTION_RR(mask)) && ret <= 0)
		write(1, "\n", 1);
	return (0);
}
