/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:35:19 by claferri          #+#    #+#             */
/*   Updated: 2023/08/17 16:27:22 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str *	free_struct(int n, t_stock_str * table)
{
	while (n)
	{
		free(table[n].copy);
		n--;
	}
	free(table);
	table = NULL;
	return (table);
}


struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	int j;
	int size;
	struct s_stock_str *struct_table;

// Get Size and allocate
	i = 0;
	j = 0;
	size = 0;
	struct_table = malloc((ac + 1) * sizeof(t_stock_str));
	if (struct_table == NULL)
			return (struct_table);
// For each string write the struct
	i = 0;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
			j++;
		struct_table[i].size = j + 1;
		struct_table[i].str = av[i];
		struct_table[i].copy = malloc((j + 1) * sizeof(char));
// If fails - free all
		if (struct_table[i].copy == NULL)
			return (free_struct(i + 1, struct_table));
		j = 0;
		while (av[i][j])
		{
			struct_table[i].copy[j] = av[i][j];
			j++;
		}
		struct_table[i].copy[j] = av[i][j];
		i++;
	}
// Last struct str is 0.
	struct_table[i].str = NULL;
	struct_table[i].copy = NULL;
	struct_table[i].size = 0;
	return (struct_table);
}


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