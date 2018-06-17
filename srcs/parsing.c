/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:54:45 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 17:46:05 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					prev_check_flag(t_union *un, char *str)
{
	int				i;

	if (!str || str[0] != '-')
		return (0);
	if (str[0] == '-' && ft_strlen(str) == 1)
		return (0);
	if (un->data || un->error)
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'l' && str[i] != 'R'
			&& str[i] != 'a' && str[i] != 'r'
				&& str[i] != 't' && str[i] != '1'
					&& str[i] != 'f')
			return (0);
		++i;
	}
	return (1);
}

int					check_flag(t_union *un, char *str)
{
	int				i;

	if (!prev_check_flag(un, str))
		return (0);
	i = 0;
	while (str[++i])
	{
		if (str[i] == 'l')
			un->flag_out.l = 1;
		else if (str[i] == 'R')
			un->flag_out.r_big = 1;
		else if (str[i] == 'a')
			un->flag_out.a = 1;
		else if (str[i] == 'r')
			un->flag_out.r = 1;
		else if (str[i] == 't')
			un->flag_out.t = 1;
		else if (str[i] == 'f')
			un->flag_out.f = 1;
		else if (str[i] == '1')
			un->flag_out.one = 1;
		else
			return (0);
	}
	return (1);
}

static inline void	print_usage(char *str)
{
	ft_printf(RED"ft_ls: illegal option -- %s\n", str + 1);
	ft_printf("usage: [-1Ralrtf] [file ...]\n"RESET);
}

static inline void	dir(int fd, t_union *un, char *str)
{
	close(fd);
	un->flag_un.found_dir = 1;
	un->data = data_container_push_back(un->data,
		str, ".");
}

void				parse_input(t_union *un, int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY) < 0))
		{
			if (!un->flag_un.found_dir && !check_flag(un, argv[i]))
			{
				if (!un->data && !un->error && argv[i][0] && argv[i][0] == '-')
				{
					print_usage(argv[i]);
					exit(666);
				}
				else
					un->error = container_push_back(un->error, argv[i]);
			}
			else if (un->flag_un.found_dir)
				un->error = container_push_back(un->error, argv[i]);
		}
		else
			dir(fd, un, argv[i]);
		++i;
	}
}
