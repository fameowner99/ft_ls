/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:42:56 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/06 18:51:48 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		main_part(t_union *un)
{
	sort_list_error(&un->error, ascending);
	print_list_error(un->error);
    sort_list_data(&un->data, ascending);

	if (un->data)
	{
		if (!un->flag_out.l)
			print_files(un->data);
	}
}
