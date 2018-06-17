/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:54:31 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/17 17:58:09 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			get_type_of_file(struct stat s)
{
	s.st_mode = (s.st_mode & S_IFMT);
	if (S_ISREG(s.st_mode))
		return ('-');
	else if (S_ISDIR(s.st_mode))
		return ('d');
	else if (S_ISLNK(s.st_mode))
		return ('l');
	else if (S_ISBLK(s.st_mode))
		return ('b');
	else if (S_ISFIFO(s.st_mode))
		return ('p');
	else if (S_ISSOCK(s.st_mode))
		return ('s');
	else if (S_ISCHR(s.st_mode))
		return ('c');
	else
		return ('-');
}

void				print_permission(t_data *data)
{
	ft_printf(MAGENTA"%c", get_type_of_file(*data->stat));
	ft_printf((data->stat->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((data->stat->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((data->stat->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((data->stat->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((data->stat->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((data->stat->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((data->stat->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((data->stat->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((data->stat->st_mode & S_IXOTH) ? "x "RESET : "- "RESET);
}

static void			print_total(t_data *data, t_union un)
{
	t_data			*tmp;
	long int		total;

	total = 0;
	tmp = data;
	while (tmp)
	{
		if (tmp->str[0] == '.')
		{
			if (un.flag_out.a || un.flag_out.f)
				total += tmp->stat->st_blocks;
		}
		else
			total += tmp->stat->st_blocks;
		tmp = tmp->next;
	}
	if (total)
		ft_printf(BGREEN"total %li\n"RESET, total);
}

static void			info_l(t_data *tmp, t_data *data, t_union un)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*str;
	char			*buff;

	grp = getgrgid(tmp->stat->st_gid);
	pwd = getpwuid(tmp->stat->st_uid);
	find_lngth(data, &un.table);
	print_permission(tmp);
	ft_printf(BCYAN"%*i "RESET, un.table.before_link,
				tmp->stat->st_nlink);
	ft_printf(GREEN"%*s  "RESET, un.table.before_name, pwd->pw_name);
	ft_printf(GREEN"%*s "RESET, un.table.before_group, grp->gr_name);
	ft_printf(RED"%*li "RESET, un.table.before_size, tmp->stat->st_size);
	str = ctime(&tmp->stat->st_ctimespec.tv_sec);
	ft_printf(BCYAN"%.*s "RESET, ft_strlen(str) - 12, str + 3);
	ft_printf(GREEN"%s"RESET, tmp->str);
	if ((S_ISLNK(tmp->stat->st_mode)))
	{
		buff = ft_memalloc(500);
		readlink(tmp->path, buff, 500);
		ft_printf(" -> %s", buff);
		free(buff);
	}
	ft_printf("\n");
}

void				print_l(t_data *data, int f, t_union un)
{
	t_data			*tmp;

	tmp = data;
	!f ? print_total(data, un) : 0;
	while (tmp)
	{
		if (f)
		{
			if (!tmp->dir)
			{
				if (tmp->str && tmp->str[0] == '.')
					un.flag_out.a ? info_l(tmp, data, un) : 0;
				else
					info_l(tmp, data, un);
			}
		}
		else
		{
			if (tmp->str && tmp->str[0] == '.')
				un.flag_out.a ? info_l(tmp, data, un) : 0;
			else
				info_l(tmp, data, un);
		}
		tmp = tmp->next;
	}
}
