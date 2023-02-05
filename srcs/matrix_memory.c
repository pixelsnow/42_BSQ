/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:21:58 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:03:11 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	malloc_matrix(int ***matrix, int height, int width)
{
	int	i;

	*matrix = (int **)malloc(sizeof(int *) * height);
	i = 0;
	while (i < height)
	{
		(*matrix)[i] = (int *)malloc(sizeof(int) * width);
		i++;
	}
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
