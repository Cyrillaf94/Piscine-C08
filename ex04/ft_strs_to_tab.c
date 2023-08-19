/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:35:19 by claferri          #+#    #+#             */
/*   Updated: 2023/08/19 11:48:38 by claferri         ###   ########.fr       */
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
		table[i].size = j;
		table[i].str = av[i];
		table[i].copy = malloc((j + 1) * sizeof(char));
		if (table[i].copy == NULL)
			if (i )
			return (free_struct(i - 1, table));
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
	if (ac < 1 || *av == NULL)
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


void print_result(t_stock_str *result, int ac) {
    for (int i = 0; i < ac; i++) {
        printf("Original: %s\n", result[i].str);
        printf("Copy: %s\n", result[i].copy);
        printf("Size: %d\n", result[i].size);
        printf("----\n");
	}
}

/*
int main() {
    t_stock_str *result;

    // Test 1: Zero arguments
    printf("Test 1: Zero arguments\n");
    result = ft_strs_to_tab(0, NULL);
    if (result == NULL) {
        printf("Result is NULL as expected\n");
    }
    printf("------\n");

    // Test 2: Single argument of zero length
    printf("\nTest 2: Single argument of zero length\n");
    char *av1[] = {""};
    result = ft_strs_to_tab(1, av1);
    print_result(result, 1);
    free(result[0].copy);
    free(result);

    // Test 3: Multiple arguments with some of zero length
    printf("\nTest 3: Multiple arguments with some of zero length\n");
    char *av2[] = {"hello", "", "world"};
    result = ft_strs_to_tab(3, av2);
    print_result(result, 3);
    for (int i = 0; i < 3; i++) {
        free(result[i].copy);
    }
    free(result);

    return 0;
}
*/
