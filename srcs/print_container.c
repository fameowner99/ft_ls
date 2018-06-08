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

static int		find_length_of_column(int min)
{
	int			width;

	width = 8;
	while (min + 1 > width)
	{
		width += 8;
	}
	return (width - 1);
}

static int		find_max_length(t_data *head)
{
	t_data	*tmp;
	int			max;

	max = 0;
	tmp = head;
	while (tmp)
	{
		if (ft_strlen(tmp->str) > max)
			max = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (max);
}

static int		find_number_of_columns()
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	ft_printf ("columns %d\n", w.ws_col);
	return (w.ws_col);
}

void			print_files(t_data *head)
{
	t_data	*tmp;
	int			s;
	int			i;
	int			c;
	
	tmp = head;
	s = find_length_of_column(find_max_length(head));
	c = find_number_of_columns() / (s);
	ft_printf(YELLOW"%i\n"RESET, c);
	i = 0;
	while (tmp)
	{
		ft_printf(GREEN"%-*s "RESET, s, tmp->str);
		tmp = tmp->next;
		++i;
		if (i == c)
		{
			i = 0;
			ft_printf("\n");
		}
	}
	ft_printf("\n");
}
