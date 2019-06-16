/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:31:07 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/16 22:36:08 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4

bool	ft_isconstrespected(int grid[N][N], int view[N][N],
		int row, int col, int i);

int		ft_isempty(int grid[N][N], int *row, int *col)
{
	int		r;
	int		c;

	r = 0;
	while (r < N)
	{
		c = 0;
		while (c < N)
		{
			if (grid[r][c] == 0)
			{
				*row = r;
				*col = c;
				return (true);
			}
			c++;
		}
		r++;
	}
	return (false);
}

void	print_table(int grid[N][N])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			write(1, &" ", 1);
			j++;
		}
		i++;
		write(1, &"\n", 1);
	}
}

bool	ft_solve(int grid[N][N], int view[N][N])
{
	int		row;
	int		col;
	int		i;

	i = 1;
	if (ft_isempty(grid, &row, &col) == false)
		return (true);
	while (i <= N)
	{
		if (ft_isconstrespected(grid, view, row, col, i) == true)
		{
			grid[row][col] = i;
			if (ft_solve(grid, view))
				return (true);
			grid[row][col] = 0;
		}
		i++;
	}
	return (false);
}
