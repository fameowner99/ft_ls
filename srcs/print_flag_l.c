/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:54:31 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/12 14:54:32 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


static char		get_type_of_file(struct stat s)
{
	s.st_mode = (s.st_mode  & S_IFMT);
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
void		print_permission(t_data	*data)
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
	ft_printf((data->stat->st_mode & S_IXOTH) ? "x  "RESET : "-  "RESET);
}
int find_lngth(t_data *data, int v, int *size)
{
	int max;
	t_data *tmp;
	int 	l;
	long 	tmp_size;

	max = 0;
	tmp = data;
	while (tmp)
	{
		l = tmp->stat->st_nlink;
		v = 0;
		tmp_size = (long)tmp->stat->st_size;
		while (l)
		{
			l /= 10;
			++v;
		}
		if (v > max)
			max = v;
		v = 0;
		while (tmp_size)
		{
			tmp_size /= 10;
			++v;
		}
		if (v > *size)
			*size = v;
		tmp = tmp->next;
	}
	return (max);
}

static void		print_all_info_l(t_data *tmp, t_data *data)
{
	struct passwd *pwd;
	struct group	*grp;
	char 	*str;
	int size;

	size = 0;
	grp = getgrgid(tmp->stat->st_gid);
	pwd = getpwuid(tmp->stat->st_uid);
	print_permission(tmp);
	ft_printf(BCYAN"%*i "RESET, find_lngth(data, 0, &size) ,tmp->stat->st_nlink);
	ft_printf(GREEN"%s "RESET, pwd->pw_name);
	ft_printf(GREEN"%s "RESET, grp->gr_name);
	ft_printf(RED"%*li "RESET, size, tmp->stat->st_size);
	str = ctime(&tmp->stat->st_mtimespec.tv_sec);
	ft_printf(BCYAN"%.*s "RESET, ft_strlen(str) - 9, str);
	ft_printf(GREEN"%s"RESET, tmp->str);
}

void		print_files_l(t_union *un)
{
	t_data	*tmp;


	tmp = un->data;
	while (tmp)
	{
		//if (!tmp->dir)
		//{
		print_all_info_l(tmp, un->data);


			ft_printf("\n");
		//}
		tmp = tmp->next;
	}
}
