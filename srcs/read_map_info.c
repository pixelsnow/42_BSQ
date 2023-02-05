/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:23:38 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:14:36 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "queue.h"

// Return 1 if need to return width already, otherwise 0.
int	newline_found(int *width, int *n_new_line, char ch)
{
	if (ch == '\n')
	{
		(*n_new_line)++;
		if ((*n_new_line) == 2)
			return (1);
	}
	else
	{
		if ((*n_new_line) == 1)
			(*width)++;
	}
	return (0);
}

// Width could easily be more than buffer size.
// Line legth returned without '\n'.
// Returns 0 if invalid/empty.
int	calculate_width(t_queue *q)
{
	t_node	*node;
	int		width;
	int		n_new_line;
	int		i;

	node = q->first;
	if (!node)
		return (0);
	width = 0;
	n_new_line = 0;
	while (node)
	{
		i = 0;
		while ((node->data)[i] != '\0')
		{
			if (newline_found(&width, &n_new_line, (node->data)[i]))
				return (width);
			i++;
		}
		node = node->next;
	}
	return (0);
}

int	read_n_lines(t_queue *q, int end)
{
	int		j;
	char	*line_num;
	int		res;

	j = 0;
	while (j < end && q->first->data[j] >= '0' && q->first->data[j] <= '9')
		j++;
	if (j != end)
		return (0);
	line_num = malloc(sizeof(char) * end + 1);
	if (!line_num)
		exit(1);
	line_num[end] = '\0';
	j = 0;
	while (j < end)
	{
		line_num[j] = q->first->data[j];
		j++;
	}
	res = ft_atoi(line_num);
	free(line_num);
	return (res);
}

// Reads map info from the first line. If the map is invalid, returns 0.
// If map is valid, fills the map info and returns 1.
int	read_map_info(t_queue *q, t_map_info *map_info)
{
	int		i;

	i = 0;
	while (q->first->data[i] != '\n' && q->first->data[i] != '\0')
		i++;
	if (i < 4 || q->first->data[i] == '\0')
		return (0);
	map_info->empty_ch = q->first->data[i - 3];
	map_info->obst_ch = q->first->data[i - 2];
	map_info->full_ch = q->first->data[i - 1];
	if (any_two_equal(map_info->empty_ch, map_info->obst_ch, map_info->full_ch))
		return (0);
	map_info->l_length = calculate_width(q);
	if (!(map_info->l_length))
		return (0);
	map_info->n_lines = read_n_lines(q, i - 3);
	if (!(map_info->n_lines))
		return (0);
	return (1);
}
