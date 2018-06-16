/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data_container.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:30:28 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/16 14:14:02 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_data		*data_container_new(char *str, char *curr_path)
{
	t_data			*res;
	struct stat		*s;

	if (!(res = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (!(res->str = (char *)ft_memalloc(ft_strlen(str) + 1)))
		return (NULL);
	if (!(s = (struct stat *)malloc(sizeof(struct stat))))
		return (NULL);
	if (!(res->curr_dir = (char *)ft_memalloc(ft_strlen(curr_path) + 1)))
		return (NULL);
	res->str = ft_strcpy(res->str, str);
	res->path = conc_next_dir(curr_path, str);
	res->curr_dir = ft_strcpy(res->curr_dir, curr_path);
	stat(res->path, s);
	res->stat = s;
	res->next = NULL;
	res->dir = S_ISDIR(res->stat->st_mode);
	return (res);
}

t_data				*data_container_push_back(t_data *head,
		char *str, char *curr_path)
{
	t_data			*tmp;
	t_data			*new;

	tmp = head;
	if (!tmp)
		return (data_container_new(str, curr_path));
	while (tmp->next)
		tmp = tmp->next;
	new = data_container_new(str, curr_path);
	tmp->next = new;
	return (head);
}

void				free_data_container(t_data *head)
{
	t_data			*tmp;
	int				i;

	i = 0;
	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head->stat);
		free(head->path);
		free(head->curr_dir);
		head->str = NULL;
		head->stat = NULL;
		head->path = NULL;
		head->next = NULL;
		head->curr_dir = NULL;
		free(head);
		head = tmp;
		++i;
	}
}
