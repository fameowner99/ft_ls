/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:08:40 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 16:56:45 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int			count_argc(int argc, char **argv, t_union un)
{
	int		i;
	int		c;

	c = 0;
	i = 1;
	while (i < argc)
	{
		if (c || argv[i][0] != '-')
			++c;
		++i;
	}
	return (c - find_length_of_list(un.error));
}

static inline void	different_flags(t_union un)
{
	if (un.data)
		choose_sort(&un.data, un);
	if (un.flag_out.r_big)
		recursion_helper(&un);
	if (un.flag_out.l && !un.flag_out.r_big)
	{
		if (un.flag_un.arg)
		{
			print_l(un.data, 1, un);
			check_exist_files(&un);
			print_all_directories(un.data, un);
		}
		else
		{
			un.data = create_data(".");
			choose_sort(&un.data, un);
			print_directory(".", un, un.data);
			if (un.data)
				free_data_container(un.data);
		}
	}
}

static void			set_v(t_union *un)
{
	un->error = NULL;
	un->data = NULL;
	un->flag_un.found_dir = 0;
	un->flag_un.found_file = 0;
	un->flag_un.one_dir = 0;
}

int					check_if_empty_dir(t_data *data, t_union un)
{
	t_data			*tmp;
	int				c;

	c = 0;
	tmp = data;
	while (tmp)
	{
		++c;
		tmp = tmp->next;
	}
	if ((un.flag_out.a || un.flag_out.f) && c)
		return (1);
	if (!un.flag_out.a && !un.flag_out.f && c > 2)
		return (1);
	return (0);
}

void				ft_ls(int argc, char **argv)
{
	t_union	un;

	set_flag(&un);
	set_v(&un);
	parse_input(&un, argc, argv);
	un.flag_un.arg = count_argc(argc, argv, un);
	if (un.error)
	{
		sort_list_error(&un.error, ascending_er);
		print_list_error(un.error);
		clear_error_container(&un);
		if (un.flag_un.arg == 0)
			return ;
	}
	if (!un.flag_out.r_big && !un.flag_out.l)
	{
		if ((un.flag_un.arg == 1 && !ft_strcmp(argv[1], "."))
				|| un.flag_un.arg == 0)
			un.data = create_data(".");
		choose_sort(&un.data, un);
		main_part(&un, argv);
	}
	different_flags(un);
	if (un.data)
		free_data_container(un.data);
}
