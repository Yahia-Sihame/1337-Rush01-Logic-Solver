/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:49:01 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/07/27 16:49:10 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *c);

void	print_char(char c);

int		str_len(char *c);

void	initialize_matrix(int matrix[4][4]);

void	print_matrix(int matrix[4][4]);

int		cm_top_bottom(int matrix[4][4], int *tab);

int		cm_left_right(int matrix[4][4], int *tab);

int	get_count_faces(int *lines)
{
	int	i;
	int	max;
	int	face;

	max = 0;
	face = 0;
	i = 0;
	while (i <= 3)
	{
		if (lines[i] > max)
		{
			max = lines[i];
			face++;
		}
		i++;
	}
	return (face);
}

int	get_count_faces_reversed(int *lines)
{
	int	i;
	int	max;
	int	face;

	max = 0;
	face = 0;
	i = 3;
	while (i >= 0)
	{
		if (lines[i] > max)
		{
			max = lines[i];
			face++;
		}
		i--;
	}
	return (face);
}

int	num_valid(int matrix[4][4], int row, int col, int val)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (matrix[row][x] == val || matrix[x][col] == val)
			return (0);
		x++;
	}
	return (1);
}

int	fill_matrix(int matrix[4][4], int *tab, int row, int col)
{
	int	val;

	if (row == 4)
		return (cm_top_bottom(matrix, tab) && cm_left_right(matrix, tab));
	val = 1;
	while (val <= 4)
	{
		if (num_valid(matrix, row, col, val))
		{
			matrix[row][col] = val;
			if (col == 3)
			{
				if (fill_matrix(matrix, tab, row + 1, (col + 1) % 4))
					return (1);
			}
			else
			{
				if (fill_matrix(matrix, tab, row, (col + 1) % 4))
					return (1);
			}
			matrix[row][col] = 0;
		}
		val++;
	}
	return (0);
}
