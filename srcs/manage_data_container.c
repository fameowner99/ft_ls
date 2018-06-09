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

static t_data	*data_container_new(char *str, struct stat *s)
{
    t_data		    *res;
    DIR             *dir;

    if (!(res = (t_data *)malloc(sizeof(t_data))))
        return (NULL);
    if (!(res->str = (char *)ft_memalloc(ft_strlen(str) + 1)))
        return (NULL);
    res->str = ft_strcpy(res->str, str);
    res->stat = s;
    res->next = NULL;
    if ((dir = opendir(str)))
        res->dir = 1;
    else
        res->dir = 0;
    if (res->dir)
        closedir(dir);
    dir = NULL;
    return (res);
}

t_data			*data_container_push_back(t_data *head, char *str, struct stat *s)
{
    t_data		*tmp;
    t_data	    *new;

    tmp = head;
    if (!tmp)
        return (data_container_new(str, s));
    while (tmp->next)
        tmp = tmp->next;
    new = data_container_new(str,s);
    tmp->next = new;
    return (head);
}