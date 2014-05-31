/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 04:18:03 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 19:56:13 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	print_link(t_hash *opt)
{
	char	op[256];
	ssize_t	back;

	write(1, " -> ", 4);
	if (((back = readlink(((opt->content->src)
							? opt->content->src
							: opt->content->name), op, 256))) == -1)
	{
		perror(opt->content->name);
		return (0);
	}
	*(op + back) = 0;
	write(1, op, ft_strlen(op));
	return (1);
}

char	print_time(time_t file_time, const char *t, int kik, int i)
{
	time_t	currtime;

	if (time(&currtime) == -1)
		return (0);
	if ((currtime - file_time) >= (60 * 60 * 24 * 366))
	{
		while (*(t + ++kik) != ' ')
			;
		write(1, t + kik, 7);
		kik = -1;
		while (*(t + ++kik))
			;
		i = kik;
		while (*(t + --kik) != ' ')
			;
		write_space(5 - (i - kik - 1));
		write(1, t + kik, i - kik - 1);
	}
	else
	{
		while (*(t + ++kik) != ' ')
			;
		write(1, t + kik, 13);
	}
	return (1);
}

void	gr_uid(t_file *content, int *len)
{
	if (!(content->uid = getpwuid(content->info.st_uid)))
		return ;
	if (!(content->grp = getgrgid(content->info.st_gid)))
		return ;
	write(1, content->uid->pw_name, ft_strlen(content->uid->pw_name));
	write_space(len[2] + 2 - ft_strlen(content->uid->pw_name));
	write(1, content->grp->gr_name, ft_strlen(content->grp->gr_name));
	write_space(len[3] + 2 - ft_strlen(content->grp->gr_name));
}

char	print_l(t_hash *opt, int *len)
{
	char	*t;
	int		kik;
	int		i;

	i = 0;
	kik = -1;
	if (!(t = ctime(&opt->content->info.st_mtime)))
		t = "fail time";
	if (opt->content)
	{
		print_right(opt->content->info.st_mode);
		write_space(len[1] + 1 - ft_nblen(opt->content->info.st_nlink));
		ft_putnbr(opt->content->info.st_nlink);
		write(1, " ", 1);
		gr_uid(opt->content, len);
		write_space((len[0] + 2 - ft_nblen(opt->content->info.st_size)));
		ft_putnbr(opt->content->info.st_size);
		if (!(print_time(opt->content->info.st_mtime, t, kik, i)))
			return (0);
		write(1, " ", 1);
	}
	return (1);
}

void	print_right(mode_t mode)
{
	if (S_ISDIR(mode))
		write(1, "d", 1);
	else if (S_ISLNK(mode))
		write(1, "l", 1);
	else if (S_ISSOCK(mode))
		write(1, "s", 1);
	else if (S_ISBLK(mode))
		write(1, "b", 1);
	else if (S_ISCHR(mode))
		write(1, "c", 1);
	else if (S_ISFIFO(mode))
		write(1, "p", 1);
	else if (S_ISREG(mode))
		write(1, "-", 1);
	else
		write(1, "?", 1);
	write(1, ((S_IRUSR & mode)) ? "r" : "-", 1);
	write(1, ((S_IWUSR & mode)) ? "w" : "-", 1);
	write(1, ((S_IXUSR & mode)) ? "x" : "-", 1);
	write(1, ((S_IRGRP & mode)) ? "r" : "-", 1);
	write(1, ((S_IWGRP & mode)) ? "w" : "-", 1);
	write(1, ((S_IXGRP & mode)) ? "x" : "-", 1);
	write(1, ((S_IROTH & mode)) ? "r" : "-", 1);
	write(1, ((S_IWOTH & mode)) ? "w" : "-", 1);
	write(1, ((S_IXOTH & mode)) ? "x" : "-", 1);
}
