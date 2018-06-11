/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:53:02 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/10 13:53:05 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*conc_next_dir(char *prev, char *next)
{
	char	*res;
	int 	i;
	int 	j;


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

static void    recursion(char *curr_dir, t_union *un)
{
    t_data          *tmp;
    t_data          *data;
	static char 			*next_dir = NULL;

    data = create_data(curr_dir);
    //sort
	if (next_dir)
		ft_printf("\n");
	ft_printf(BYELLOW"%s:\n"RESET, data->curr_dir);
    print_directory(curr_dir, *un, data);
    tmp = data;
    while (tmp)
    {
        if (tmp->dir && tmp->str && ft_strcmp(tmp->str, "..") && ft_strcmp(tmp->str, "."))
        {
			if (tmp->str[0] == '.')
			{
				if (un->flag_out.a) {
					next_dir = conc_next_dir(curr_dir, tmp->str);
					recursion(next_dir, un);
				}
			}
			else
			{
				next_dir = conc_next_dir(curr_dir, tmp->str);
				recursion(next_dir, un);
			}
        }
        tmp = tmp->next;
    }
	free_data_container(data);

}

void			recursion_helper(t_union *un)
{
	t_data		*tmp;


    if (!un->flag_un.arg)
        recursion(ft_strdup("."), un);
	else
	{
		tmp = un->data;
		print_files(un->data, *un);
		while (tmp)
		{
			if (tmp->dir && tmp->str)
				recursion(tmp->str, un);
			tmp = tmp->next;
		}

	}
}
