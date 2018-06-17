/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:05:10 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 18:56:47 by vmiachko         ###   ########.fr       */
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
# include <pwd.h>
# include <time.h>
# include <grp.h>

typedef struct			s_flag_out
{
	int					l;
	int					r_big;
	int					a;
	int					r;
	int					t;
	int					f;
	int					one;
}						t_flag_out;

typedef struct			s_flag_un
{
	int					found_dir;
	int					error_after_dir;
	int					arg;
	int					found_file;
	int					one_dir;
}						t_flag_un;

typedef struct			s_container
{
	char				*str;
	struct s_container	*next;
}						t_container;

typedef struct			s_data
{
	char				*str;
	char				*path;
	char				*curr_dir;
	int					dir;
	struct stat			*stat;
	struct s_data		*next;
}						t_data;

typedef struct			s_table
{
	int					before_link;
	int					before_name;
	int					before_group;
	long				before_size;
}						t_table;

typedef struct			s_union
{
	t_flag_out			flag_out;
	t_flag_un			flag_un;
	t_container			*error;
	t_data				*data;
	t_table				table;

}						t_union;

/*
** container error will
** contain all invalied directories
** container valid will contain all valid
** directories which content should be print
*/

void					set_flag(t_union *un);
void					ft_ls(int argc, char **argv);
void					parse_input(t_union *un, int argc, char **argv);
t_container				*container_push_back(t_container *head, char *str);
void					sort_list_error(t_container **head,
							int (*cmp)(char*, char*));
void					print_list_error(t_container *head);
int						ascending(t_data tmp1, t_data tmp2);
void					main_part(t_union *un, char **argv);
void					print_files(t_data *head, t_union un);
t_data					*data_container_push_back(t_data *head,
								char *str, char *curr_path);
void					sort_list_data(t_data **head,
								int (*cmp)(t_data tmp1, t_data tmp2));
int						find_length_of_list(t_container *lst);
int						find_number_of_columns(void);
int						find_max_length(t_data *head);
int						find_length_of_column(int min);
void					print_all(t_data *head, t_union un);
void					print_directory(char *str, t_union un, t_data *data);
void					print_all_directories(t_data *data, t_union un);
void					check_exist_files(t_union *un);
t_data					*create_data(char *str);
void					recursion_helper(t_union *un);
char					*conc_next_dir(char *prev, char *next);
void					free_data_container(t_data *head);
void					print_l(t_data *data, int f, t_union un);
void					find_lngth(t_data *data, t_table *table);
void					clear_error_container(t_union *un);
int						ascending_er(char *str1, char *str2);
int						ascending_r(t_data tmp1, t_data tmp2);
int						ascending_time(t_data tmp1, t_data tmp2);
void					choose_sort(t_data **data, t_union un);
int						ascending_time_r(t_data tmp1, t_data tmp2);
void					recursion(char *curr_dir, t_union *un, char *next_dir);
int						check_if_empty_dir(t_data *data, t_union un);

#endif
