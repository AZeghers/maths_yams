/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** arg parsing
*/

#include "yams.h"

int		check_underscores(char *str)
{
	int	i = 0;
	int	flag = 0;

	while (str[i]) {
		if (str[i] == '_') {
			if (flag)
				return (1);
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	return (0);
}

void		to_res(char *num1, char *num2, int *res)
{
	if (num1) {
		if (strlen(num1) != 1)
			res[0] = CVALUE;
		res[1] = atoi(num1);
		if (res[1] > 6 || res[1] <= 0)
			res[0] = CVALUE;
	}
	else
		res[0] = COMB;
	if (res[0] != FULL && num2)
		res[0] = COMB;
	if (num2) {
		if (strlen(num2) != 1)
			res[0] = CVALUE;
		res[2] = atoi(num2);
		if (res[2] > 6 || res[2] <= 0 || num2[1])
			res[0] = CVALUE;
	}
}

void		get_type(char *arg, int *res)
{
	char	*type;
	char	*num1;
	char	*num2;
	int	i = 0;
	char	*tab[6] = { "pair", "three", "four",
			    "full", "straight", "yams"
	};

	if (!strlen(arg) || arg[strlen(arg) - 1] == '_' ||
	    arg[0] == '_' || check_underscores(arg))
	{
		res[0] = COMB;
		return;
	}
	type = strtok(arg, "_");
	num1 = strtok(NULL, "_");
	num2 = strtok(NULL, "_");
	while (i < 6) {
		if (!strcmp(type, tab[i]))
			res[0] = i;
		i++;
	}
	to_res(num1, num2, res);
	if (strtok(NULL, "_"))
		res[0] = SYNTAX;
}

void		parse(char **argv, int *res)
{
	int	i;

	res[0] = COMB;
	get_type(argv[6], res);
	for (i = 1; i < 6; i++) {
		if ((strlen(argv[i]) != 1) ||
		    ((argv[i][0] > '6') || (argv[i][0] < '0')))
			res[0] = DVALUE;
		res[i + 2] = atoi(argv[i]);
		if (res[i + 2] > 6 || res[i + 2] < 0)
			res[0] = DVALUE;
	}
	if (((res[0] == FULL) && ((res[1] == res[2]) || (res[2] == 0))) ||
	    ((res[0] == STRAIGHT) && (res[1] < 5)))
		res[0] = CVALUE;
}
