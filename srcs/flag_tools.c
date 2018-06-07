/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:06:06 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/05 13:43:47 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	set_flag(t_union *un)
{
	un->flag_out.l = 0;
	un->flag_out.R = 0;
	un->flag_out.a = 0;
	un->flag_out.r = 0;
	un->flag_out.t = 0;
	un->flag_un.found_dir = 0;
	un->flag_un.error_after_dir = 0;
}

