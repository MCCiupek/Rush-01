/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constraints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:31:26 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/16 22:40:10 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#define N 4

bool	ft_checkviewsh(int grid[N][N], int row, int i, int rowl, int rowr);
bool	ft_checkviewsv(int grid[N][N], int col, int i, int colu, int cold);

bool	ft_notinrow(int grid[N][N], int row, int i)
{
	int	col;

	col = 0;
	while (col < N)
	{
		if (grid[row][col] == i)
			return (false);
		col++;
	}
	return (true);
}

bool	ft_notincol(int grid[N][N], int col, int i)
{
	int	row;

	row = 0;
	while (row < N)
	{
		if (grid[row][col] == i)
			return (false);
		row++;
	}
	return (true);
}

bool	ft_iscolcomplete(int grid[N][N], int col)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < N)
	{
		if (grid[i][col] != 0)
			count++;
		i++;
	}
	if (count == N)
		return (true);
	return (false);
}

bool	ft_isrowcomplete(int grid[N][N], int row)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < N)
	{
		if (grid[row][i] != 0)
			count++;
		i++;
	}
	if (count == N)
		return (true);
	return (false);
}

bool	ft_isconstrespected(int grid[N][N], int v[N][N], int row,
		int col, int i)
{
	bool	colcomplete;
	bool	rowcomplete;

	colcomplete = ft_iscolcomplete(grid, col);
	rowcomplete = ft_isrowcomplete(grid, row);
	if (ft_notinrow(grid, row, i) == true &&
			ft_notincol(grid, col, i) == true)
	{
		if (colcomplete == true && rowcomplete == true &&
				ft_checkviewsh(grid, row, i, v[2][row], v[3][row]) == true &&
				ft_checkviewsv(grid, col, i, v[0][col], v[1][col]) == true)
			return (true);
		else if (colcomplete == true && rowcomplete == false &&
				ft_checkviewsv(grid, col, i, v[0][col], v[1][col]) == true)
			return (true);
		else if (colcomplete == false && rowcomplete == true &&
				ft_checkviewsh(grid, row, i, v[2][row], v[3][row]) == true)
			return (true);
		else if (colcomplete == false && rowcomplete == false)
			return (true);
	}
	return (false);
}
