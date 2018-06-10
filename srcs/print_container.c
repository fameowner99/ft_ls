/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:45:19 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/07 14:55:33 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		find_length_of_column(int min)
{
	int			width;

	width = 8;
	while (min + 1 > width)
	{
		width += 8;
	}
	return (width - 1);
}

int		find_max_length(t_data *head, t_union un)
{
	t_data	*tmp;
	int			max;

	max = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->str && tmp->str[0] != '.' && ft_strlen(tmp->str) > max)
			max = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (max);
}

int		find_number_of_columns()
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

void			print_files(t_data *head, t_union un)
{
	t_data	*tmp;
	int			s;
	int			i;
	int			c;
	
	tmp = head;
	s = find_length_of_column(find_max_length(head, un));
	c = (find_number_of_columns() + find_max_length(head, un) - s)/ (s + 1);
    if (c == 0)
        c = 1;
	i = 0;
	while (tmp)
	{
        if (!tmp->dir)
			ft_printf(GREEN"%-*s "RESET, s, tmp->str);
		tmp = tmp->next;
		++i;
		if (i == c)
		{
			i = 0;
            if (tmp)
			ft_printf("\n");
		}
	}
    if (un.flag_un.found_dir && un.flag_un.found_file)
	    ft_printf("\n");
}
