/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 22:12:29 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 21:10:19 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLS_H
# define MYLS_H

# include "libc.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <stdio.h>
# include <sys/stat.h>
# include <pwd.h>
# include <errno.h>
# include <grp.h>
# include <time.h>
# include <string.h>

# define OPTS "lratR"
# define OPTION_L(x) (x & (char) 1)
# define OPTION_R(x) (x & (char) 2)
# define OPTION_A(x) (x & (char) 4)
# define OPTION_T(x) (x & (char) 8)
# define OPTION_RR(x) (x & (char) 16)
# define MOVEC(x, y) (*(opt->hash + (x >> (8 * y)) % 256))->content
# define MOVET(x) (*(opt->hash + (x % 256)))->content
# define MOVEA(x, y) (*(opt->hash + ((x >> (8 * y)) % 256)))
# define UN __attribute__ ((unused))

typedef const unsigned char	t_cast;

typedef struct		s_file
{
	char			*src;
	char			*name;
	size_t			len;
	char			acces;
	struct passwd	*uid;
	struct group	*grp;
	struct stat		info;
}					t_file;

typedef struct		s_hash
{
	struct s_hash	*hash[256];
	t_file			*content;
}					t_hash;

typedef struct		s_thash
{
	struct s_thash	*hash[256];
	t_hash			*content;
}					t_thash;

typedef struct		s_val
{
	DIR				*ptr;
	struct dirent	*dir;
	t_file			*ret;
	int				*len;
	t_hash			opt;
	t_thash			topt;
}					t_val;

void				init_lens(int *len);
int					*init_value(int *len, t_thash *topt, t_hash *opt);
char				push_dirs(t_file *ret, int *len);
char				map_hash(char mask, t_thash *topt, t_hash *opt
					, t_file *ret);
char				ft_insert_telm(time_t time, t_file *ret, t_thash *opt
					, const size_t pow);
char				ft_insert_elm(t_cast *name, t_file *ret, t_hash *opt);
void				free_thash(t_thash *opt);
void				free_hash(t_hash *ptr);
void				biglen(t_file *ret, int *len);
char				ft_mask(char *str, const char *ref);
char				mask_arg(char **av, char *options);
char				load_dir(char *path, char mask, int is);
char				is_end(char mask, t_thash *topt, t_hash *opt, int *len);
DIR					*open_dirs(char *path, char mask, int is);
char				recur(t_hash *opt, char mask);
char				recur_t(t_thash *topt, char mask);
char				print_thash(t_thash *topt, char mask, int *len);
char				print_hash(t_hash *opt, char mask, int *len);
char				print_link(t_hash *opt);
char				print_time(time_t file_time, const char *t, int kik, int i);
char				print_l(t_hash *opt, int *len);
void				print_right(mode_t mode);
void				write_space(size_t nb);
char				is_hidden_file(const char *str);
char				concat_t(char *path, t_file *ret, struct dirent *dir);
char				*concat_slash(char *path, char *name);
char				*concat_string(char *path, char *name);

#endif
