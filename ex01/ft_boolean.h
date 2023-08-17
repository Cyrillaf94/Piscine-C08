/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:29:14 by claferri          #+#    #+#             */
/*   Updated: 2023/08/17 18:48:08 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(n) ((n) % 2 == 0)

# define EVEN_MSG "I have an even number of arguments."

# define ODD_MSG "I have an odd number of arguments."

# define SUCCESS 0

typedef enum t_bool {
	FALSE,
	TRUE
}	t_bool;

#endif