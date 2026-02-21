/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:36:21 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/07/27 16:38:10 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initialize_matrix(int matrix[4][4]);

int		fill_matrix(int matrix[4][4], int *table, int row, int col);

void	print_matrix(int matrix[4][4]);

void	print_str(char *c);

int		str_len(char *c);

int	check_argv(char *argv, int *tab)
{
	int	i;
	int	vlen;

	i = 0;
	vlen = str_len(argv);
	while (i < vlen)
	{
		if ( (i % 2 == 0)   &&( argv[i] >= '0' && argv[i] <= '9'))
			tab[i / 2] = argv[i] - '0';
		else if (!((i % 2 == 1) && argv[i] == ' ') )
		{
			print_str("Error\n");
			return 0;
		}
		i += 2;
	}
	return 1 ; 
}

int	main(int argc, char **argv)
{
	int	tab[16];
	int	matrix[4][4];

	if (argc == 2)
	{
		if (str_len(argv[1]) != 31)
		{
			print_str("Error\n");
			return (1);
		}
		if (!check_argv(argv[1], tab))
		{
			return 1; 
		}
		initialize_matrix(matrix);
		if (fill_matrix(matrix, tab, 0, 0))
		{
			print_matrix(matrix);
			return (0);
		}
		else
		{
			print_str("Error\n");
			return (1);
		}
	}
	print_str("Error\n");
	return (1);
}
