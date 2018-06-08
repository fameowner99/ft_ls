/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data_container.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:30:28 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/06 18:36:56 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_data	*data_container_new(char *str, DIR *dir, struct stat *s)
{
    t_data		    *res;

    if (!(res = (t_data *)malloc(sizeof(t_data))))
        return (NULL);
    if (!(res->str = (char *)ft_memalloc(ft_strlen(str) + 1)))
        return (NULL);
    res->str = ft_strcpy(res->str, str);
    res->dir = dir;
    res->stat = s;
    res->next = NULL;
    return (res);
}

t_data			*data_container_push_back(t_data *head, char *str, DIR *dir, struct stat *s)
{
    t_data		*tmp;
    t_data	    *new;

    tmp = head;
    if (!tmp)
        return (data_container_new(str, dir, s));
    while (tmp->next)
        tmp = tmp->next;
    new = data_container_new(str, dir, s);
    tmp->next = new;
    return (head);
}