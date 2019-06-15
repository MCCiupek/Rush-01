/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sudoku4x4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:20:41 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/15 16:45:15 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

bool ft_isEmpty(int grid[4][4])
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (grid[row][col] == 0)
				return true;
			col++;
		}
		row++;
	}
	return false;
}

bool ft_NotInRow(int grid[4][4], int row, int i)
{
	int col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == i)
			return false;
		col++;
	}
	return true;
}

bool ft_NotInCol(int grid[4][4], int col, int i)
{
	int row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == i)
			return false;
		row++;
	}
	return true;
}


bool ft_checkViewsH(int grid[4][4], int row, int i, int colU, int colD)
{
	int col;
	int viewU;
	int viewD;
	int max;

	viewU = 1;
	col = 1;
	max = grid[row][0];
	while (col < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewU++;
		}
		col++;
	}

	viewD = 1;
	col = 2;
	max = grid[row][3];
	while (col >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewD++;
		}
		col--;
	}

	if (viewU <= colU && viewD <= colD)
		return true;
	return false;
}

bool ft_checkViewsV(int grid[4][4], int col, int i, int rowL, int rowR)
{
	int row;
	int viewL;
	int viewR;
	int max;

	viewL = 1;
	row = 1;
	max = grid[0][col];
	while (row < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewL++;
		}
		row++;
	}

	viewR = 1;
	row = 2;
	max = grid[3][col];
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			viewR++;
		}
		row--;
	}

	if (viewL <= rowL && viewR <= rowR)
		return true;
	return false;
}

/*bool ft_isConstRespected(int *grid, int row, int col, int i) 
{
	if (ft_inRow(grid, row, i) == true &&
			ft_inCol(grid, row, i) == true &&
			ft_CheckViewsV(grid, col, i, rowL, rowR) == true &&
			ft_CheckViewsH(grid, row, i, colU, colD) == true)
		return true;
	return false;
}

bool ft_Solve(int **grid)
{
	int row;
	int col;
	int i;

	i = 1;
	if (!ft_isEmpty(grid, row, col))
		return true;

	while (i <= 4)
	{
		if (ft_isConstRespected(grid, row, col, i))
		{
			grid[row][col] = i;
			if (ft_Solve(grid))
				return true;
			grid[row][col] = 0;
		}
		i++;
	}
	return false;
}*/

int main(void)
{
	int n = 4;
	int grid[4][4] = {{1, 2, 3, 4},
						{2, 0, 0, 0},
						{4, 0, 0, 0},
						{4, 0, 0, 0}};
	printf("%d\n", ft_isEmpty(grid));
	printf("%d\n", ft_NotInRow(grid, 1, 1));
	printf("%d\n", ft_NotInCol(grid, 1, 1));
	printf("%d\n", ft_checkViewsH(grid, 1, 1, 3, 2));
	printf("%d\n", ft_checkViewsV(grid, 1, 1, 3, 2));
	//ft_Solve(grid);
}
