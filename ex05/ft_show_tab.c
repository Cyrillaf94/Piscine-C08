/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:08:09 by claferri          #+#    #+#             */
/*   Updated: 2023/08/17 18:44:30 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ex04/ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

t_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < -2147483647)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

void	ft_show_tab(t_stock_str *tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i].str)
	{
		ft_putstr(tab[i].str);
		write(1, "\n", 1);
		ft_putnbr(tab[i].size);
		write(1, "\n", 1);
		ft_putstr(tab[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

/*
int main() {
    char *samples[] = {
        "apple",
        "banana",
        "cherry"
    };
    int size = sizeof(samples) / sizeof(samples[0]);

    t_stock_str *result = ft_strs_to_tab(size, samples);

    if (!result) {
        write(1, "Error in memory allocation.\n", 28);
        return 1;
    }

    ft_show_tab(result);

    int i = 0;
    while (result[i].str) {
        free(result[i].copy);
        i++;
    }
    free(result);

    return 0;
}
*/
