/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:06:45 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:10:25 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "queue.h"

// Convert and add a symbol to int array matrix
// (obstacle -> 0, free -> 1)
// A symbol is already checked for validity by valid_symbol().
void	write_valid_symbol(int **matrix, t_map_info *map_info,
		t_vector xy, char ch)
{
	int	value;

	if (ch == map_info->empty_ch)
		value = 1;
	else if (ch == map_info->obst_ch)
		value = 0;
	else
		value = -1;
	matrix[xy.y][xy.x] = solve_matrix(matrix, map_info, xy, value);
}

// Returns 1 if symbol added ok to matrix; if invalid symbol/error returns 0
// -1 if newline
int	symbol_to_matrix(int **matrix, t_vector *xy, t_map_info *map_info, char ch)
{
	if (ch == '\n')
	{
		if (xy->x != map_info->l_length)
			return (0);
		else
		{
			xy->y++;
			xy->x = 0;
		}
		if (xy->y > map_info->n_lines)
			return (0);
	}
	else
	{
		if (!valid_symbol(*map_info, ch) || xy->y >= map_info->n_lines)
			return (0);
		write_valid_symbol(matrix, map_info, *xy, ch);
		xy->x++;
	}
	return (1);
}

// Read strings from queue and puts them into a matrix of ints.
// Checks the validity of the map in the process
// (each char, line length, total number of lines).
// If everything went well, return 1. If error (invalid map), return 0.
int	data_to_matrix(t_queue *q, int **matrix, t_map_info *map_info)
{
	t_vector	xy;
	t_node		*node;
	int			i;

	node = q->first;
	if (!node)
		return (0);
	i = go_to_data_start(node, 0);
	xy.x = 0;
	xy.y = 0;
	while (node)
	{
		while ((node->data)[i] != '\0')
		{
			if (!symbol_to_matrix(matrix, &xy, map_info, (node->data)[i]))
				return (0);
			i++;
		}
		node = node->next;
		i = 0;
	}
	if (map_info->n_lines != xy.y)
		return (0);
	return (1);
}

// Returns 1 if the map is valid, 0 otherwise.
// Transforms the queue into a string and fills out the string and map info.
// If the map is invalid, clean the queue and return 0.
int	queue_to_matrix(t_queue *q, int ***matrix, t_map_info *map_info)
{
	if (!read_map_info(q, map_info))
		return (0);
	malloc_matrix(matrix, map_info->n_lines, map_info->l_length);
	if (!*matrix)
		exit(1);
	if (data_to_matrix(q, *matrix, map_info))
		return (1);
	else
		return (0);
}

// Takes the queue and processes it
void	process_queue(t_queue *q)
{
	int			**matrix;
	t_map_info	*map_info;

	matrix = NULL;
	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!map_info)
		exit(1);
	init_map_info(map_info);
	if (queue_to_matrix(q, &matrix, map_info))
		print_largest_square(matrix, *map_info);
	else
		display_error();
	free_matrix(matrix, map_info->n_lines);
	free(map_info);
}
