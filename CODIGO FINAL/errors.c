/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:25:26 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/22 14:28:38 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_open_fd(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "invalid FD.\n\033[0m", 17);
	exit(EXIT_FAILURE);
}

int	map_error(int n)
{
	if (n == 1)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "irregular map proportions or walls.\n\033[0m", 41);
	}
	if (n == 2)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "number or type of itens invalid.\n\033[0m", 38);
	}
	if (n == 3)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "map path invalid.\n\033[0m", 23);
	}
	return (0);
}
