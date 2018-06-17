/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:17:46 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 17:52:04 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			sort_list_error(t_container **head, int (*cmp)(char*, char*))
{
	t_container	*tmp1;
	t_container	*tmp2;
	char		*str_tmp;

	tmp1 = *head;
	while (tmp1)
	{
		tmp2 = *head;
		while (tmp2->next)
		{
			if (!cmp(tmp2->str, tmp2->next->str))
			{
				str_tmp = tmp2->str;
				tmp2->str = tmp2->next->str;
				tmp2->next->str = str_tmp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

static void		my_swap(t_data **tmp2)
{
	char		*str_tmp;
	int			dir;
	struct stat *s;

	str_tmp = (*tmp2)->str;
	dir = (*tmp2)->dir;
	s = (*tmp2)->stat;
	(*tmp2)->str = (*tmp2)->next->str;
	(*tmp2)->dir = (*tmp2)->next->dir;
	(*tmp2)->stat = (*tmp2)->next->stat;
	(*tmp2)->next->str = str_tmp;
	(*tmp2)->next->dir = dir;
	(*tmp2)->next->stat = s;
	str_tmp = (*tmp2)->path;
	(*tmp2)->path = (*tmp2)->next->path;
	(*tmp2)->next->path = str_tmp;
	str_tmp = (*tmp2)->curr_dir;
	(*tmp2)->curr_dir = (*tmp2)->next->curr_dir;
	(*tmp2)->next->curr_dir = str_tmp;
}

void			sort_list_data(t_data **head, int (*cmp)(t_data, t_data))
{
	t_data		*tmp1;
	t_data		*tmp2;

	tmp1 = *head;
	while (tmp1)
	{
		tmp2 = *head;
		while (tmp2->next)
		{
			if (!cmp(*tmp2, *tmp2->next))
				my_swap(&tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void			choose_sort(t_data **data, t_union un)
{
	if (un.flag_out.f)
		return ;
	else if (un.flag_out.t && !un.flag_out.r)
		sort_list_data(data, ascending_time);
	else if (un.flag_out.t && un.flag_out.r)
		sort_list_data(data, ascending_time_r);
	else if (!un.flag_out.t && un.flag_out.r)
		sort_list_data(data, ascending_r);
	else
		sort_list_data(data, ascending);
}
