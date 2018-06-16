/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:42:56 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/16 14:08:29 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		main_part(t_union *un, char **argv)
{
	if (un->data && un->flag_un.arg &&
			!(un->flag_un.arg == 1 && !ft_strcmp(".", argv[1])))
	{
		check_exist_files(un);
		print_files(un->data, *un);
		print_all_directories(un->data, *un);
	}
	else if (un->data)
		print_directory(".", *un, un->data);
}
