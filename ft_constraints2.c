/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constraints2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:33:14 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/16 22:43:29 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#define N 4

int		ft_hl(int grid[N][N], int row);
int		ft_hr(int grid[N][N], int row);
int		ft_vu(int grid[N][N], int col);
int		ft_vd(int grid[N][N], int col);

bool	ft_checkviewsh(int grid[N][N], int row, int i, int rowl, int rowr)
{
	int		viewr;
	int		viewl;

	grid[row][3] = i;
	viewl = ft_hl(grid, row);
	viewr = ft_hr(grid, row);
	if (viewl == rowl && viewr == rowr)
		return (true);
	grid[row][3] = 0;
	return (false);
}

bool	ft_checkviewsv(int grid[N][N], int col, int i, int colu, int cold)
{
	int		viewu;
	int		viewd;

	grid[3][col] = i;
	viewu = ft_vu(grid, col);
	viewd = ft_vd(grid, col);
	if (viewu == colu && viewd == cold)
		return (true);
	grid[3][col] = 0;
	return (false);
}
