/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:47:11 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 12:53:32 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	count_map_featuress(char **arr, int *pande, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'E' || arr[i][j] == 'P')
				(*pande)++;
			else if (arr[i][j] == 'C')
				(*c)++;
			else if (arr[i][j] != 'E' && arr[i][j] != 'P' && arr[i][j] != 'C'
				&& arr[i][j] != '0' && arr[i][j] != '1' && arr[i][j] != '\n')
				return ;
			if (arr[i][j] == 'T' && arr[i][j - 1] != 'B')
				return ;
			j++;
		}
		i++;
	}
}
