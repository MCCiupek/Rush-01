/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constraints2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:33:14 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/16 22:34:13 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#define N 4

int		ft_hl(int grid[N][N], int row)
{
	int	col;
	int	viewl;
	int	max;

	col = 1;
	viewl = 1;
	max = grid[row][0];
	while (col < N)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewl++;
		}
		col++;
	}
	return (viewl);
}

int		ft_hr(int grid[N][N], int row)
{
	int	col;
	int	viewr;
	int	max;

	col = 2;
	viewr = 1;
	max = grid[row][N - 1];
	while (col >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewr++;
		}
		col--;
	}
	return (viewr);
}

int		ft_vu(int grid[N][N], int col)
{
	int row;
	int	viewu;
	int	max;

	viewu = 1;
	row = 1;
	max = grid[0][col];
	while (row < N)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewu++;
		}
		row++;
	}
	return (viewu);
}

int		ft_vd(int grid[N][N], int col)
{
	int row;
	int	viewd;
	int	max;

	viewd = 1;
	row = 2;
	max = grid[N - 1][col];
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewd++;
		}
		row--;
	}
	return (viewd);
}
