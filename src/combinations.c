/*
** EPITECH PROJECT, 2018
** combinations
** File description:
** algorithmes des combinaisons
*/

#include "yams.h"

double		pair(int c, int *dice)
{
	double	res = 0.0;
	int	right = 0;
	int	i = 0;

	if (is_done(c, dice, 2)) {
		res = 1.0;
		return (res);
	}
	right = how_many_right(c, dice);
	while (right + i < 5) {
		res = res + binomiale(5.0 - (double)right, 2.0 - (double)right + (double)i);
		i++;
	}
	return (res);
}

double		three(int c, int *dice)
{
	double	res = 0.0;
	int	right = 0;
	int	i = 0;

	if (is_done(c, dice, 3)) {
		res = 1.0;
		return (res);
	}
	right = how_many_right(c, dice);
	while (right + i < 5) {
		res = res + binomiale(5.0 - (double)right, 3.0 - (double)right + (double)i);
		i++;
	}
	return (res);
}

double		four(int c, int *dice)
{
	double	res = 0.0;
	int	right = 0;
	int	i = 0;

	if (is_done(c, dice, 4)) {
		res = 1.0;
		return (res);
	}
	right = how_many_right(c, dice);
	while (right + i < 5) {
		res = res + binomiale(5.0 - (double)right, 4.0 - (double)right + (double)i);
		i++;
	}
	return (res);
}

double		yams(int c, int *dice)
{
	double	res = 0.0;
	int	right = 0;
	int	i = 0;

	if (is_done(c, dice, 5)) {
		res = 1.0;
		return (res);
	}
	right = how_many_right(c, dice);
	while (right + i < 5) {
		res = res + binomiale(5.0 - (double)right, 5.0 - (double)right + (double)i);
		i++;
	}
	return (res);
}

double		full(int c1, int c2, int *dice)
{
	double	res = 0.0;
	int	right1 = 0;
	int	right2 = 0;
	int	done1 = 0;
	int	done2 = 0;

	done1 = is_done(c1, dice, 3);
	done2 = is_done(c2, dice, 2);
	right1 = how_many_right(c1, dice);
	right2 = how_many_right(c2, dice);
	if (done1 && done2) {
		res = 1.0;
		return (res);
	}
	if (right1 > 3)
		right1 = 3;
	if (right2 > 2)
		right2 = 2;
	res = ((fact(5 - right2 - right1)) /
	       ((fact(3 - right1)) * (fact((5 - right2 - right1) - (3 - right1)))));
	res *= power(1.0/6.0, 5 - right2 - right1);
	return (res);
}

double		straight(int c, int *dice)
{
	double	res = 1.0/6.0;
	int	i;
	int	j = 0;
	int	right[5] =  {0, 0, 0, 0, 0};
	int	count = 5;

	while (j < 5) {
		i = 0;
		while (i < 5) {
			if (dice[i] == j + c - 4) {
				if (!right[j])
					count--;
				right[j] = 1;
			}
			i++;
		}
		j++;
	}
	res = fact(count) * power(res, count);
	return (res);
}
