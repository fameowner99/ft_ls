/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:34:58 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/16 18:04:16 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			set_table(t_table *table)
{
	table->before_group = 0;
	table->before_link = 0;
	table->before_name = 0;
	table->before_size = 0;
}

static t_table		curr_lngth(t_table tmp_table)
{
	t_table			counter;

	set_table(&counter);
	while (tmp_table.before_size)
	{
		tmp_table.before_size /= 10;
		++counter.before_size;
	}
	while (tmp_table.before_name)
	{
		tmp_table.before_name /= 10;
		++counter.before_name;
	}
	while (tmp_table.before_link)
	{
		tmp_table.before_link /= 10;
		++counter.before_link;
	}
	while (tmp_table.before_group)
	{
		tmp_table.before_group /= 10;
		++counter.before_group;
	}
	return (counter);
}

void				find_lngth(t_data *data, t_table *table)
{
	t_data			*tmp;
	t_table			tmp_table;
	t_table			counter;
	struct group	*grp;

	set_table(table);
	tmp = data;
	while (tmp)
	{
		grp = getgrgid(tmp->stat->st_gid);
		tmp_table.before_link = tmp->stat->st_nlink;
		tmp_table.before_name = (int)ft_strlen(tmp->str);
		tmp_table.before_group = (int)ft_strlen(grp->gr_name);
		tmp_table.before_size = (long)tmp->stat->st_size;
		counter = curr_lngth(tmp_table);
		table->before_link < counter.before_link ?
				table->before_link = counter.before_link : 0;
		table->before_name < counter.before_name ?
				table->before_name = counter.before_name : 0;
		table->before_size < counter.before_size ?
				table->before_size = counter.before_size : 0;
		table->before_group < counter.before_group ?
				table->before_group = counter.before_group : 0;
		tmp = tmp->next;
	}
}
