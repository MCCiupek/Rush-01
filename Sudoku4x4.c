/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sudoku4x4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:20:41 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/15 19:05:37 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4

int ft_isEmpty(int grid[N][N], int *row, int *col)
{
	int r;
	int c;

	r = *row;
	while (r < N)
	{
		c = *col;
		while (c < N)
		{
			if (grid[r][c] == 0)
			{
				*row = r;
				*col = c;
				return true;
			}
			c++;
		}
		r++;
	}
	return false;
}

bool ft_NotInRow(int grid[N][N], int row, int i)
{
	int col;

	col = 0;
	while (col < N)
	{
		if (grid[row][col] == i)
			return false;
		col++;
	}
	return true;
}

bool ft_NotInCol(int grid[N][N], int col, int i)
{
	int row;

	row = 0;
	while (row < N)
	{
		if (grid[row][col] == i)
			return false;
		row++;
	}
	return true;
}


bool ft_checkViewsH(int grid[N][N], int row, int i, int colU, int colD)
{
	int col;
	int viewU;
	int viewD;
	int max;

	viewU = 1;
	col = 1;
	max = grid[row][0];
	while (col < N)
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
	max = grid[row][N - 1];
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

bool ft_checkViewsV(int grid[N][N], int col, int i, int rowL, int rowR)
{
	int row;
	int viewL;
	int viewR;
	int max;

	viewL = 1;
	row = 1;
	max = grid[0][col];
	while (row < N)
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
	max = grid[N - 1][col];
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

bool ft_isConstRespected(int grid[N][N], int view[N][N], int row, int col, int i) 
{
	if (ft_NotInRow(grid, row, i) == true &&
			ft_NotInCol(grid, row, i) == true &&
			ft_checkViewsV(grid, col, i, view[0][col], view[1][col]) == true &&
			ft_checkViewsH(grid, row, i, view[2][row], view[3][row]) == true)
		return true;
	return false;
}

bool ft_Solve(int grid[N][N], int view[N][N])
{
	int row;
	int col;
	int i;
	
	row = 0;
	col = 0;
	i = 1;
	if (ft_isEmpty(grid, &row, &col) == -1)
		return true;

	while (i <= N)
	{
		if (ft_isConstRespected(grid, view, row, col, i))
		{
			grid[row][col] = i;
			if (ft_Solve(grid, view))
				return true;
			grid[row][col] = 0;
		}
		i++;
	}
	return false;
}

int main(void)
{
	int n = 3;
	int row = 1;
	int col = 1;
	int grid[N][N] = {{1, 2, 3, 4},
						{2, 0, 0, 0},
						{4, 0, 0, 0},
						{4, 0, 0, 0}};

	int view[N][N] = {{4, 3, 2, 1},
						{1, 2, 2, 2},
						{4, 3, 2, 1},
						{1, 2, 2, 2}};

	//printf("is empty = %d\n", ft_isEmpty(grid, 0, 0));
	printf("not in row = %d\n", ft_NotInRow(grid, row, n));
	printf("not in col = %d\n", ft_NotInCol(grid, col, n));
	printf("views h = %d\n", ft_checkViewsH(grid, row, n, view[0][col], view[1][col]));
	printf("views v = %d\n", ft_checkViewsV(grid, col, n, view[2][row], view[3][row]));
	printf("TOTAL CONST = %d\n", ft_isConstRespected(grid, view, row, col, n));
	ft_Solve(grid, view);
}
