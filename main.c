/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:35:59 by mashar            #+#    #+#             */
/*   Updated: 2019/06/16 23:15:42 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define N 4

int		check_argv(int argc, char **argv);
void	ft_complete(int str[N*N], int grind[N][N]);
bool	ft_solve(int grid[N][N], int view[N][N]);
void	print_table(int grid[N][N]);

int		main(int argc, char **argv)
{
	int view[N * N];
	int v[N][N];
	int i;
	int j;
	int k;
	//int grid[N][N];
	
	i = 0;
	j = 0;
	if (check_argv(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (j < N * N)
	{
		view[j] = argv[1][i] - '0';
		j++;
		i = i + 2;
	}
	int grid[N][N] = {{0 ,0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}};
	ft_complete(view, grid);
	j = 0;
	while (j < N)
	{
		k = 0;
		while (k < N)
		{
			v[j][k] = view[i];
			k++;
			i++;
		}
		j++;
	}
	if (ft_solve(grid, v) == true)
	{
		print_table(grid);
		return (1);
	}
	return (0);
}
