/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:47:01 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/18 11:10:02 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			print_f(t_union un, int s, t_data *tmp)
{
	if (tmp->str[0] == '.')
	{
		if (un.flag_out.a || un.flag_out.f)
			ft_printf(GREEN"%-*s "RESET, s, tmp->str);
	}
	else
		ft_printf(GREEN"%-*s "RESET, s, tmp->str);
}

static inline void	new_line(int *i, int c, t_data *tmp, t_union un)
{
	if (*i == c)
	{
		*i = 0;
		if (check_if_empty_dir(tmp, un))
			ft_printf("\n");
	}
}

void				print_all(t_data *head, t_union un)
{
	t_data		*tmp;
	int			s;
	int			i;
	int			c;

	tmp = head;
	s = find_length_of_column(find_max_length(head));
	c = (find_number_of_columns() +
			find_max_length(head) - s) / (s + 1);
	(c == 0 || un.flag_out.one) ? c = 1 : 0;
	i = 0;
	while (tmp)
	{
		print_f(un, s, tmp);
		if (!((!un.flag_out.a && tmp->str[0] == '.')
					&& (!un.flag_out.f && tmp->str[0])))
			++i;
		tmp = tmp->next;
		new_line(&i, c, tmp, un);
	}
	if (check_if_empty_dir(head, un))
		write(1, "\n", 1);
}

void				print_directory(char *str, t_union un, t_data *data)
{
	if (un.flag_un.arg)
	{
		if (!un.flag_un.one_dir && !un.flag_out.r_big)
			ft_printf(BYELLOW"%s:\n"RESET, str);
		un.flag_out.l ? print_l(data, 0, un) : print_all(data, un);
	}
	else
		un.flag_out.l ? print_l(data, 0, un) : print_all(data, un);
}

void				print_all_directories(t_data *data, t_union un)
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
				write(1, "\n", 1);
			dir_data = create_data(tmp->str);
			choose_sort(&dir_data, un);
			print_directory(tmp->str, un, dir_data);
			free_data_container(dir_data);
			i = 1;
		}
		tmp = tmp->next;
	}
}
