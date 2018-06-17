/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:53:02 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 18:57:07 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*conc_next_dir(char *prev, char *next)
{
	char			*res;
	int				i;
	int				j;

	res = (char *)ft_memalloc(ft_strlen(prev) + ft_strlen(next) + 2);
	i = 0;
	while (prev[i])
	{
		res[i] = prev[i];
		++i;
	}
	if (i > 0 && prev[i - 1] != '/')
		res[i++] = '/';
	j = 0;
	while (next[j])
	{
		res[i] = next[j];
		++j;
		++i;
	}
	return (res);
}

static void			body(t_data *tmp, t_union *un,
							char *next_dir, char *curr_dir)
{
	if (tmp->str[0] == '.')
	{
		if (un->flag_out.a)
		{
			next_dir = conc_next_dir(curr_dir, tmp->str);
			recursion(next_dir, un, next_dir);
			if (next_dir)
				free(next_dir);
		}
	}
	else
	{
		next_dir = conc_next_dir(curr_dir, tmp->str);
		recursion(next_dir, un, next_dir);
		if (next_dir)
			free(next_dir);
	}
}

void				recursion(char *curr_dir, t_union *un, char *next_dir)
{
	t_data			*tmp;
	t_data			*data;
	static int 		i = 0;

	data = create_data(curr_dir);
	choose_sort(&data, *un);
	if (!data)
		return ;
	if (i || un->flag_un.found_file)
		ft_printf("\n");
	un->flag_un.found_file = 0;
	(i || un->flag_un.arg) ? ft_printf(BYELLOW"%s:\n"RESET, data->curr_dir) : 0;
	print_directory(curr_dir, *un, data);
	tmp = data;
	i = 1;
	while (tmp)
	{
		if (tmp->dir && tmp->str && ft_strcmp(tmp->str, "..")
				&& ft_strcmp(tmp->str, "."))
			body(tmp, un, next_dir, curr_dir);
		tmp = tmp->next;
	}
	free_data_container(data);
}

void				recursion_helper(t_union *un)
{
	t_data			*tmp;

	if (!un->flag_un.arg)
		recursion(".", un, NULL);
	else
	{
		tmp = un->data;
		check_exist_files(un);
		print_files(un->data, *un);
		while (tmp)
		{
			if (tmp->dir && tmp->str)
				recursion(tmp->str, un, NULL);
			tmp = tmp->next;
		}
	}
}
