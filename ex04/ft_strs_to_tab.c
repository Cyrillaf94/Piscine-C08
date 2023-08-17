/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:35:19 by claferri          #+#    #+#             */
/*   Updated: 2023/08/17 19:27:05 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*free_struct(int n, t_stock_str *table)
{
	while (n >= 0)
	{
		free(table[n].copy);
		n--;
	}
	free(table);
	table = NULL;
	return (table);
}

struct s_stock_str	*ft_copy_strings(int ac, char **av, t_stock_str *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
			j++;
		table[i].size = j + 1;
		table[i].str = av[i];
		table[i].copy = malloc((j + 1) * sizeof(char));
		if (table[i].copy == NULL)
			return (free_struct(i, table));
		j = 0;
		while (av[i][j])
		{
			table[i].copy[j] = av[i][j];
			j++;
		}
		table[i].copy[j] = av[i][j];
		i++;
	}
	return (table);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	int					j;
	int					size;
	struct s_stock_str	*struct_table;

	i = 0;
	j = 0;
	size = 0;
	struct_table = NULL;
	if (ac < 1)
		return (struct_table);
	struct_table = malloc((ac + 1) * sizeof(t_stock_str));
	if (struct_table == NULL)
		return (struct_table);
	struct_table = ft_copy_strings(ac, av, struct_table);
	struct_table[ac].str = NULL;
	struct_table[ac].copy = NULL;
	struct_table[ac].size = 0;
	return (struct_table);
}

/*
void display_tab(t_stock_str *tab) {
    int i = 0;
    while (tab[i].str) {
        printf("Size: %d\n", tab[i].size);
        printf("Str: %s\n", tab[i].str);
        printf("Copy: %s\n\n", tab[i].copy);
        i++;
    }
}

int main() {
    char *samples[] = {
        "apple",
        "banana",
        "cherry"
    };
    int size = sizeof(samples) / sizeof(samples[0]);

    t_stock_str *result = ft_strs_to_tab(size, samples);

    if (!result) {
        printf("Error in memory allocation.\n");
        return 1;
    }

    display_tab(result);

    int i = 0;
    while (result[i].str) {
        free(result[i].copy);
        i++;
    }
    free(result);

    return 0;
}
*/
