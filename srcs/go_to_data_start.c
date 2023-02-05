/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_data_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:38:13 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:15:02 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

// Return the index of the first data line inside the node
// Assumption: node is larger than 1st line of file, thus contans the start
// of data too
int	go_to_data_start(t_node *node, int i)
{
	while ((node->data)[i] != '\0')
	{
		if ((node->data)[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}
