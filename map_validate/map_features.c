/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:48:11 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/11 15:47:44 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_map_features(char **arr, int *pande, int *c, int *enemy)
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
			else if (arr[i][j] == 'T' || arr[i][j] == 'B')
				(*enemy)++;
			if (arr[i][j] == 'T' && arr[i][j - 1] != 'B')
				return ;
			j++;
		}
		i++;
	}
}

int	validate_map_features_custom(char **arr)
{
	int	pande;
	int	enemy;
	int	c;

	pande = 0;
	enemy = 0;
	c = 0;
	count_map_features(arr, &pande, &c, &enemy);
	if (pande != 2)
		return (error_fct(pande));
	if (c < 1)
		return (error_fct(c));
	if (enemy != 2)
		return (error_fct(enemy));
	return (0);
}



int calculate_width(char **arr, t_mlx *win)
{
    int j;
    int last_column_index;

    j = 0;
    last_column_index = 0;
    while (arr[0][j] != '\0')
    {
        last_column_index = j;
        j++;
    }
    j--;
    win->width = j;
	last_column_index--;
	return(last_column_index);
}

int calculate_height(char **arr, t_mlx *win)
{
    int i;
    int last_row_index;

    i = 0;
    last_row_index = 0;
    while (arr[i] != NULL)
    {
        last_row_index = i;
        i++;
    }
    win->height = last_row_index + 1;
	return(last_row_index);
}

int	validate_map_element(char **arr, t_mlx *win)
{
	int	i;
	int	valid;
	int	j;
	int	last_row_index;
	int	last_column_index;

	last_row_index = calculate_height(arr, win);
	last_column_index = calculate_width(arr, win);
	j = 0;
	while (j <= last_column_index)
	{
		if (arr[0][j] != '1' || arr[last_row_index][j] != '1')
			return (error_fct(1));
		j++;
	}
	i = 0;
	while (i <= last_row_index)
	{
		if (arr[i][0] != '1' || arr[i][last_column_index] != '1')

			return (error_fct(1));
		i++;
	}
	valid = validate_map_features_custom(arr);
	return (valid);
}

int	validate_map_features(char **arr, t_mlx *win)
{
	int	i;
	int	j;
	int	len;
	int	valid;

	i = 0;
	len = -1;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\n' && arr[i][j] != '\0')
		{
			j++;
		}
		if (len == -1)
			len = j;
		else if (len != j)
		{
			printf("Error ->Invalid map\n");
			return (1);
		}
		i++;
	}
	valid = validate_map_element(arr, win);
	return (valid);
}
