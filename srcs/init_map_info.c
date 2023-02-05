/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:28:05 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 16:43:35 by akurusio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->obst_ch = '\0';
	map_info->full_ch = '\0';
	map_info->empty_ch = '\0';
	map_info->l_length = 0;
	map_info->n_lines = 0;
	map_info->sq_side = 0;
	map_info->sq_x = 0;
	map_info->sq_y = 0;
}
