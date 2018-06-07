/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:30:28 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/06 18:36:56 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_container	*container_new(char *str)
{
	t_container		*res;

	if (!(res = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	if (!(res->str = (char *)ft_memalloc(ft_strlen(str) + 1)))
		return (NULL);
	res->str = ft_strcpy(res->str, str);
	res->next = NULL;
	return (res);
}

t_container			*container_push_back(t_container *head, char *str)
{
	t_container		*tmp;
	t_container		*new;

	tmp = head;
	if (!tmp)
		return (container_new(str));
	while (tmp->next)
		tmp = tmp->next;
	new = container_new(str);
	tmp->next = new;
	return (head);
}

void				print_list_error(t_container *head)
{
	t_container		*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf(RED"ls: %s: No such file or directory\n"RESET, tmp->str);
		tmp = tmp->next;
	}
}
