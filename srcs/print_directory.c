/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:47:01 by vmiachko          #+#    #+#             */
/*   Updated: 2018/06/09 13:47:03 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			print_all(t_data *head, t_union un)
{
    t_data	*tmp;
    int			s;
    int			i;
    int			c;

    tmp = head;
    s = find_length_of_column(find_max_length(head));
    c = find_number_of_columns() / (s);
    i = 0;
    while (tmp)
    {
        if (tmp->str[0] != '.')
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
    ft_printf("\n");
}


void               print_directory(char *str, t_union un)
{
    DIR           *dir;
    struct dirent *dp;
    struct stat       *s;
    t_data         *data;

    data = NULL;
    if (!(dir = opendir (str)))
        exit(1);
    if (!un.flag_un.one_dir)
        ft_printf(GREEN"%s:\n"RESET, str);
    while ((dp = readdir (dir)))
    {

        s = (struct stat *)malloc(sizeof(struct stat));
        stat(str, s);
        data = data_container_push_back(data, dp->d_name, s);
    }

    //diff flags
    sort_list_data(&data, ascending);
    print_all(data, un);

}

void            print_all_directories(t_data *data, t_union un)
{
    t_data      *tmp;
    int            i;

    i = 0;
    tmp = data;
    while (tmp)
    {
        if (tmp->dir)
        {
            if (i || un.flag_un.found_file)
                ft_printf("\n");
            print_directory(tmp->str, un);
            i = 1;
        }
        tmp = tmp->next;
    }
}