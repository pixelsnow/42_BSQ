/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:12:55 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 16:42:11 by akurusio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// return min of three parameters
int	min_three(int x, int y, int z)
{
	int	min;

	if (x < y)
		min = x;
	else
		min = y;
	if (z < min)
		return (z);
	else
		return (min);
}

// Calculate the largest square for the given coordinates
int	solve_matrix(int **matrix, t_map_info *map_info, t_vector xy, int value)
{
	int	left;
	int	diag;
	int	top;
	int	res;

	if (value == 0)
		return (value);
	top = 0;
	left = 0;
	diag = 0;
	res = value;
	if (xy.y != 0)
		left = matrix[xy.y - 1][xy.x];
	if (xy.x != 0)
		top = matrix[xy.y][xy.x - 1];
	if (xy.x && xy.y)
		diag = matrix[xy.y - 1][xy.x - 1];
	res += min_three(left, diag, top);
	if (res > map_info->sq_side)
	{
		map_info->sq_side = res;
		map_info->sq_x = xy.x;
		map_info->sq_y = xy.y;
	}
	return (res);
}
