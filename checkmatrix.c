/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:27:49 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/07/27 17:27:53 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_count_faces(int *lines);

int	get_count_faces_reversed(int *lines);

int	cm_top_bottom(int matrix[4][4], int *tab)
{
	int	i;
	int	j;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = matrix[j][i];
			j++;
		}
		if (get_count_faces(line) != tab[i]
			|| get_count_faces_reversed(line) != tab[i + 4])
			return (0);
		i++;
	}
	return (1);
}

int	cm_left_right(int matrix[4][4], int *tab)
{
	int	i;
	int	j;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = matrix[i][j];
			j++;
		}
		if (get_count_faces(line) != tab[i + 8]
			|| get_count_faces_reversed(line) != tab[i + 12])
			return (0);
		i++;
	}
	return (1);
}
