/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:17:46 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/06 15:27:09 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ascending(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) < 0)
		return (1);
	return (0);
}

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

void			sort_list_data(t_data **head, int (*cmp)(char*, char*))
{
	t_data	*tmp1;
	t_data	*tmp2;
	char		*str_tmp;
	int 		dir;

	tmp1 = *head;
	while (tmp1)
	{
		tmp2 = *head;
		while (tmp2->next)
		{
			if (!cmp(tmp2->str, tmp2->next->str))
			{
				str_tmp = tmp2->str;
				dir = tmp2->dir;
				tmp2->str = tmp2->next->str;
				tmp2->dir = tmp2->next->dir;
				tmp2->next->str = str_tmp;
				tmp2->next->dir = dir;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
