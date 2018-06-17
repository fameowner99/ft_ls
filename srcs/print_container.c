/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:45:19 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 19:30:40 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					find_length_of_column(int min)
{
	int				width;

	width = 8;
	while (min + 1 > width)
	{
		width += 8;
	}
	return (width - 1);
}

int					find_max_length(t_data *head)
{
	t_data			*tmp;
	int				max;

	max = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->str && tmp->str[0] != '.' && (int)ft_strlen(tmp->str) > max)
			max = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (max);
}

static void			print_f(t_union un, int s, t_data *tmp)
{
	if (tmp->str[0] == '.')
	{
		if (un.flag_out.a)
			ft_printf(GREEN"%-*s "RESET, s, tmp->str);
	}
	else
		ft_printf(GREEN"%-*s "RESET, s, tmp->str);
}

static inline void	new_line(int *i, int c, t_data *tmp)
{
	if (*i == c)
	{
		*i = 0;
		tmp ? ft_printf("\n") : 0;
	}
}

void				print_files(t_data *head, t_union un)
{
	t_data			*tmp;
	int				s;
	int				i;
	int				c;

	tmp = head;
	s = find_length_of_column(find_max_length(head));
	c = (find_number_of_columns() +
			find_max_length(head) - s) / (s + 1);
	(c == 0 || un.flag_out.one) ? c = 1 : 0;
	i = 0;
	while (tmp)
	{
		!tmp->dir ? print_f(un, s, tmp) : 0;
		!(!un.flag_out.a && tmp->str[0] == '.') ? ++i : 0;
		tmp = tmp->next;
		new_line(&i, c, tmp);
	}
	if (un.flag_un.found_dir && un.flag_un.found_file)
		ft_printf("\n");
}
