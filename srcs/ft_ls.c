/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:08:40 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/16 14:06:06 by vmiachko         ###   ########.fr       */
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
		if (argv[i][0] != '-')
			++c;
		++i;
	}
	return (c - find_length_of_list(un.error));
}

static inline void	different_flags(t_union un)
{
	if (un.flag_out.R && !un.flag_out.l)
		recursion_helper(&un);
	if (un.flag_out.l && !un.flag_out.R)
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
			print_directory(".", un, un.data);
		}
	}
	if (un.flag_out.l && un.flag_out.R)
	{
	}
}

void				ft_ls(int argc, char **argv)
{
	t_union	un;

	set_flag(&un);
	un.error = NULL;
	un.data = NULL;
	parse_input(&un, argc, argv);
	un.flag_un.arg = count_argc(argc, argv, un);
	if (un.error)
	{
		sort_list_error(&un.error, ascending);
		print_list_error(un.error);
		clear_error_container(&un);
	}
	if (!un.flag_out.R && !un.flag_out.l)
	{
		if ((un.flag_un.arg == 1 && !ft_strcmp(argv[1], "."))
				|| un.flag_un.arg == 0)
			un.data = create_data(ft_strdup("."));
		main_part(&un, argv);
		free_data_container(un.data);
	}
	different_flags(un);
}
