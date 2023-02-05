/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:49:27 by vvagapov          #+#    #+#             */
/*   Updated: 2022/07/20 17:03:45 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_largest_square(int **matrix, t_map_info map_info)
{
	int	line;
	int	col;

	line = 0;
	while (line < map_info.n_lines)
	{
		col = 0;
		while (col < map_info.l_length)
		{
			if ((col > (map_info.sq_x - map_info.sq_side))
				&& (col <= map_info.sq_x)
				&& (line > (map_info.sq_y - map_info.sq_side))
				&& (line <= map_info.sq_y))
				ft_putchar(map_info.full_ch);
			else if (matrix[line][col])
				ft_putchar(map_info.empty_ch);
			else
				ft_putchar(map_info.obst_ch);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
