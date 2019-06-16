/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirichel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:35:14 by nirichel          #+#    #+#             */
/*   Updated: 2019/06/16 19:25:48 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define N 4

int    ft_part_top(int str[N * N], int grid[N][N], int i)
{	
	int j;
    int k;

	j = 0;
	if (str[i] == N)
	{
        k = 0;
        while (++k < N)
            grid[k - 1][i] = k;
	}
	if (str[i] == 1)
		grid[0][i] = N;
	if (str[i] == 1 && str[i + 4] == 2)
		grid[3][i] = 3;
	if (str[i] == 3 && grid[2][i] == 3)
	{
		grid[0][i] = 2;
		grid[1][i] = 1;
		grid[3][i] = 4;
	}
	else if (str[i] == 3 && grid[3][i] == 3)
	{
		grid[0][i] = 1;
		grid[1][i] = 2;
		grid[2][i] = 4;
	}
	else if (str[i] == 3 && grid[0][i] == 2)
	{
		j = 0;
		while(j < N)
		{
			if (grid[3][j] == 4)
				grid[3][i] = 1;
			if (grid[1][j] == 3)
				grid[1][i] = 1;
			j++;
		}
	}
	else if (str[i] == 3 && grid[0][i] == 1)
	{
		j = 0;
		while(j < N)
		{
			if (grid[2][j] == 4)
				grid[2][i] = 2;
			if (grid[1][j] == 3)
				grid[1][i] = 2;
			j++;
		}
	}
	return (i);
}

int    ft_part_bottom(int str[N * N], int grid[N][N], int i)
{
	if (str[i] == N)
	{
		grid[3][i - 4] = 1;
		grid[1][i - 4] = 2;
		grid[1][i - 4] = 3;
		grid[0][i - 4] = 4;
	}
	if (str[i] == 1)
		grid[3][i - 4] = 4;
	if (str[i] == 1 && str[i - 4] == 2)
		grid[0][i - 4] = 3;
	return (i);
}

int    ft_part_left(int str[N * N], int grid[N][N], int i)
{
	if (str[i] == N)
	{
		grid[i - 8][0] = 1;
		grid[i - 8][1] = 2;
		grid[i - 8][2] = 3;
		grid[i - 8][3] = 4;
	}	
	if (str[i] == 1)
		grid[i - 8][0] = 4;
	if (str[i] == 1 && str[i + 4] == 2)
		grid[i - 8][3] = 3;
	return (i);
}

int    ft_part_right(int str[N * N], int grid[N][N], int i)
{
	if (str[i] == N)
	{
		grid[i - 12][3] = 1;
		grid[i - 12][2] = 2;
		grid[i - 12][1] = 3;
		grid[i - 12][0] = 4;
	}
	if (str[i] == 1)
		grid[i - 12][3] = 4;
	if (str[i] == 1 && str[i - 4] == 2)
		grid[i - 12][0] = 3;
	return (i);
}

void	ft_complete(int str[16], int grid[4][4])
{
	int i;
	int j;

	j = 0;
    while (j <= 3)
    {
        i = 0;
        while (str[i])
        {
            if (i < 4)
                ft_part_top(str, grid, i);
            if (i > 3 && i < 8)
                ft_part_bottom(str, grid, i);
            if (i > 7 && i < 12)
                ft_part_left(str, grid, i);
            if (i > 11 && i < 16)
                ft_part_right(str, grid, i);
            i++;
        }
        j++;
    }
}
