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

	//diff sort
    sort_list_data(&un->data, ascending);



    if (un->data && un->flag_un.arg)
    {
        check_exist_files(un);
        print_files(un->data, *un);
        print_all_directories(un->data, *un);
    }
    else if (un->data)
    {
        print_directory(".", *un, un->data);
    }
    //else another output
}




