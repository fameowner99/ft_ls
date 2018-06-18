/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_of_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:51:16 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 17:50:18 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ascending(t_data tmp1, t_data tmp2)
{
	if (ft_strcmp(tmp1.str, tmp2.str) < 0)
		return (1);
	return (0);
}

int				ascending_r(t_data tmp1, t_data tmp2)
{
	if (ft_strcmp(tmp1.str, tmp2.str) < 0)
		return (0);
	return (1);
}

int				ascending_er(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) < 0)
		return (1);
	return (0);
}

int				ascending_time(t_data tmp1, t_data tmp2)
{
	long int res;

	res = tmp1.stat->st_ctimespec.tv_sec - tmp2.stat->st_ctimespec.tv_sec;
	if (!res)
	{
		res = tmp1.stat->st_ctimespec.tv_nsec - tmp2.stat->st_ctimespec.tv_nsec;
		if (!res)
			return (ascending(tmp1, tmp2));
		return (res > 0 ? 1 : 0);
	}
	return (res > 0 ? 1 : 0);
}

int				ascending_time_r(t_data tmp1, t_data tmp2)
{
	long int res;

	res = tmp1.stat->st_ctimespec.tv_sec - tmp2.stat->st_ctimespec.tv_sec;
	if (!res)
	{
		res = tmp1.stat->st_ctimespec.tv_nsec - tmp2.stat->st_ctimespec.tv_nsec;
		if (!res)
			return (ascending(tmp2, tmp1));
		return (res > 0 ? 0 : 1);
	}
	return (res > 0 ? 0 : 1);
}
