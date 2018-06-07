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
	un.file = NULL;
	un.directory = NULL;
	parse_input(&un, argc, argv);
	main_part(&un);
}
