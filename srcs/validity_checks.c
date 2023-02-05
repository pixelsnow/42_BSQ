/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:11:33 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 16:25:53 by akurusio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Return 1 if a symbol is valid, otherwise 0
int	valid_symbol(t_map_info map_info, char ch)
{
	return (ch == map_info.empty_ch || ch == map_info.obst_ch);
}

// Returns 1 if any two of the chX are equal: otherwise 0
int	any_two_equal(char ch1, char ch2, char ch3)
{
	return (ch1 == ch2 || ch2 == ch3 || ch1 == ch3);
}
