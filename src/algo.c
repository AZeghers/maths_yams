/*
** EPITECH PROJECT, 2018
** algo
** File description:
** binomiale
*/

#include "yams.h"

double		power(double nb, int pow)
{
	double	ret = 1.0;

	while (pow > 0) {
		ret *= nb;
		pow--;
	}
	return (ret);
}

int		how_many_right(int c, int *dice)
{
	int	count = 0;
	int	i = 0;

	while (i < 5) {
		if (c == dice[i])
			count++;
		i++;
	}
	return (count);
}

int		is_done(int c, int *dice, int needed)
{
	int	count = 0;
	int	i = 0;

	while (i < 5) {
		if (c == dice[i])
			count++;
		i++;
	}
	if (count >= needed)
		return (1);
	return (0);
}

double		fact(double nb)
{
	if (nb > 1.0)
		return (nb * fact(nb - 1.0));
	return (1.0);
}

double		binomiale(double n, double k)
{
	double	ncr = 0.0;
	double	p = 0.0;
	double	nop = 0.0;

	ncr = ((fact(n)) / ((fact(k)) * (fact(n - k))));
	p = power((1.0 / 6.0), k);
	nop = power((5.0 / 6.0), n - k);
	return (ncr * p * nop);
}

void		display_result(int type, int c1, int c2, double result)
{
	char	*tab[6] = {
		"pair",
		"three-of-a-kind",
		"four-of-a-kind",
		"full",
		"straight",
		"yams"
	};

	if (type == FULL) {
		printf("chances to get a %i full of %i:   %.2f%%\n", c1, c2, result);
	}
	else
		printf("chances to get a %i %s:   %.2f%%\n", c1, tab[type], result);
}

void		start_algo(int *res)
{
	double	percent = 0.0;

	switch(res[0]) {
	case PAIR:
		percent = pair(res[1], &res[3]);
		break;
	case THREE:
		percent = three(res[1], &res[3]);
		break;
	case FOUR:
		percent = four(res[1], &res[3]);
		break;
	case FULL:
		percent = full(res[1], res[2], &res[3]);
		break;
	case STRAIGHT:
		percent = straight(res[1], &res[3]);
		break;
	case YAMS:
		percent = yams(res[1], &res[3]);
		break;
	}
	display_result(res[0], res[1], res[2], percent * 100.0);
}
