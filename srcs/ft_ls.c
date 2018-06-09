/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:08:40 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/06 18:37:31 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_ls(int argc, char **argv)
{
	t_union	un;

	set_flag(&un);
	un.error = NULL;
	un.data = NULL;
    if ((argc == 2 && !ft_strcmp(argv[1], ".")) || argc == 1)
        un.flag_un.arg = 0;
    else
    {
        parse_input(&un, argc, argv);
        un.flag_un.arg = 1;
    }
    main_part(&un);
}
