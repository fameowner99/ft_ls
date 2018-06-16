/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:47:01 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/16 15:37:43 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_f(char *str, t_union un, int s, t_data *tmp)
{
	if (tmp->str[0] == '.')
	{
		if (un.flag_out.a)
			ft_printf(GREEN"%-*s "RESET, s, tmp->str);
	}
	else
		ft_printf(GREEN"%-*s "RESET, s, tmp->str);
}

void			print_all(t_data *head, t_union un)
{
	t_data		*tmp;
	int			s;
	int			i;
	int			c;

	tmp = head;
	s = find_length_of_column(find_max_length(head, un));
	c = (find_number_of_columns() + find_max_length(head, un) - s) / (s + 1);
	if (c == 0)
		c = 1;
	i = 0;
	while (tmp)
	{
		print_f(tmp->str, un, s, tmp);
		if (!(!un.flag_out.a && tmp->str[0] == '.'))
			++i;
		tmp = tmp->next;
		if (i == c)
		{
			i = 0;
			if (tmp)
				ft_printf("\n");
		}
	}
	ft_printf("\n");
}

void			print_directory(char *str, t_union un, t_data *data)
{
	if (un.flag_un.arg)
	{
		if (!un.flag_un.one_dir && !un.flag_out.R)
			ft_printf(BYELLOW"%s:\n"RESET, str);
		un.flag_out.l ? print_l(data, 0, un) : print_all(data, un);
	}
	else
		un.flag_out.l ? print_l(data, 0, un) : print_all(data, un);
}

void			print_all_directories(t_data *data, t_union un)
{
	t_data		*tmp;
	int			i;
	t_data		*dir_data;

	i = 0;
	tmp = data;
	while (tmp)
	{
		if (tmp->dir)
		{
			if (i || un.flag_un.found_file)
				ft_printf("\n");
			dir_data = create_data(tmp->str);
			print_directory(tmp->str, un, dir_data);
			free_data_container(dir_data);
			i = 1;
		}
		tmp = tmp->next;
	}
}
