/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:11:21 by mashar            #+#    #+#             */
/*   Updated: 2019/06/15 16:11:24 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_argc(int argc)
{
	if (argc != 2)
	{
		return (0);
	}
	else
		return (1);
}

int		is_valid(int i, int j, int *a, char **argv)
{
	j = 0;
	if (i % 8 == 0 && i > 1)
	{
		if (!(a[0] == 1) || !((a[1] >= 1) && (a[1] <= 3))
			|| !((a[2] >= 0) && (a[2] <= 2))
			|| !((a[3] >= 0) && (a[3] <= 1)))
			return (0);
		while (j < 4)
		{
			a[j] = 0;
			j++;
		}
	}
	if (argv[1][i] == '1')
		a[0]++;
	else if (argv[1][i] == '2')
		a[1]++;
	else if (argv[1][i] == '3')
		a[2]++;
	else if (argv[1][i] == '4')
		a[3]++;
	return (1);
}

int		check_each(char **argv)
{
	int i;
	int j;
	int a[5];

	i = 0;
	j = 0;
	while (i < 32)
	{
		if (!(is_valid(i, j, a, argv)))
			return (0);
		i = i + 2;
	}
	return (1);
}

int		check_cnt(char **argv)
{
	int i;
	int a[5];

	i = 0;
	while (i < 32)
	{
		if (argv[1][i] == '1')
			a[0]++;
		else if (argv[1][i] == '2')
			a[1]++;
		else if (argv[1][i] == '3')
			a[2]++;
		else if (argv[1][i] == '4')
			a[3]++;
		i = i + 2;
	}
	if (!(a[0] == 4) || !((a[1] >= 4) && (a[1] <= 8))
			|| !((a[2] >= 0) && (a[2] <= 6))
			|| !((a[3] >= 0) && (a[3] <= 4)) || !(check_each(argv)))
		return (0);
	return (1);
}

int		check_argv(int argc, char **argv)
{
	int i;

	i = 0;
	if (check_argc(argc) == 0)
		return (0);
	while (argv[1][i] != '\0')
	{
		if (!((argv[1][i] >= 49 && argv[1][i] <= 52) || (argv[1][i] == ' '))
				|| (argv[1][i] == argv[1][i + 1])
				|| ((argv[1][i] >= 49 && argv[1][i] <= 52)
				&& (argv[1][i + 1] >= 49 && argv[1][i + 1] <= 52)))
		{
			return (0);
		}
		i++;
	}
	if (check_cnt(argv) == 0)
	{
		return (0);
	}
	if (i != 31)
	{
		return (0);
	}
	return (1);
}
