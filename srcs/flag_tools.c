/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:06:06 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/05 13:43:47 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	set_flag(t_union *un)
{
	un->flag_out.l = 0;
	un->flag_out.R = 0;
	un->flag_out.a = 0;
	un->flag_out.r = 0;
	un->flag_out.t = 0;
	un->flag_un.found_dir = 0;
	un->flag_un.error_after_dir = 0;
}

int 		find_length_of_list(t_container *lst)
{
	t_container	*tmp;
	int 	c;

	c = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		++c;
	}
	return (c);
}

void        check_exist_files(t_union *un)
{
    t_data *tmp;
    int     c;

    c = 0;
    tmp = un->data;
    un->flag_un.found_file = 0;
    un->flag_un.one_dir = 0;
    while (tmp)
    {
        if (!tmp->dir)
            un->flag_un.found_file = 1;
        ++c;
        tmp = tmp->next;
    }
    if (c == 1 && !un->flag_un.found_file)
        un->flag_un.one_dir = 1;
}

t_data		*create_data(char *str)
{
	DIR           *dir;
	struct dirent *dp;
	struct stat       *s;
	t_data         *data;

	data = NULL;
	if (!(dir = opendir (str)))
		return (data);
	while ((dp = readdir (dir)))
	{
		s = (struct stat *)malloc(sizeof(struct stat));
		stat(str, s);
		data = data_container_push_back(data, dp->d_name, s,  str);
	}
	return (data);
}