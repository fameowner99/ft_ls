/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:05:10 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/07 14:01:44 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"

# include "dirent.h"
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_flag_out
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flag_out;

typedef struct		s_flag_un
{
	int				found_dir;
	int				error_after_dir;
}					t_flag_un;

typedef struct			s_container
{
	char				*str;
	struct s_container	*next;
}						t_container;

typedef struct 			s_data
{
	char 				*str;
	struct DIR			*dir;
	struct stat			*stat;
	struct s_data		*next;
}						t_data;

typedef struct		s_union
{
	t_flag_out		flag_out;
	t_flag_un		flag_un;
	t_container		*error;
	t_data			*data;
}					t_union;

/*
 ** container error will contain all invalied directories
 ** container valid will contain all valid directories which content should be print
*/

void				set_flag(t_union *un);
void				ft_ls(int argc, char **argv);
void				parse_input(t_union *un, int argc, char **argv);
t_container			*container_push_back(t_container *head, char *str);
void				sort_list_error(t_container **head, int (*cmp)(char*, char*));
void				print_list_error(t_container *head);
int					ascending(char *str1, char *str2);
void				main_part(t_union *un);
void				print_files(t_data *head);
t_data				*data_container_push_back(t_data *head, char *str, DIR *d, struct stat *s);
void	    		sort_list_data(t_data **head, int (*cmp)(char*, char*));
#endif
