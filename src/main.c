/*
** EPITECH PROJECT, 2018
** main 201yams
** File description:
** main
*/

#include "yams.h"

void		puterr(char *err)
{
	write(2, err, strlen(err));
}

void		usage(void)
{
	puts("USAGE");
	puts("           ./201yams d1 d2 d3 d4 d5 c\n");
	puts("DESCRIPTION");
	puts("           d1   value of the first die (0 if not thrown)");
	puts("           d2   value of the second die (0 if not thrown)");
	puts("           d3   value of the third die (0 if not thrown)");
	puts("           d4   value of the fourth die (0 if not thrown)");
	puts("           d5   value of the fifth die (0 if not thrown)");
	puts("           c    expected combination");
}

void		err(int type)
{
	switch (type) {
	case (SYNTAX) :
		puterr("Incorrect syntax, see ./201yams -h for help\n");
		break;
	case (COMB) :
		puterr("Unknown combination\n");
		break;
	case (DVALUE) :
		puterr("Dice have to be between 0 and 6, 0 if they're not thrown\n");
		break;
	case (CVALUE) :
		puterr("Dice have to be between 1 and 6 after combination name,");
		puterr(" full must have 2 different arguments, straight must be 5 or 6\n");
		break;
	}
}

int		main(int argc, char **argv)
{
	int	*res;
	int	i;

	if (argc > 1) {
		if (!strcmp(argv[1], "-h")) {
			usage();
			return (0);
		}
		if (argc == 7) {
			res = malloc(sizeof(int) * 8);
			if (res) {
				for (i = 0; i < 8; i++)
					res[i] = 0;
				parse(argv, res);
				if (res[0] > 9) {
					err(res[0]);
					free(res);
					return (84);
				}
				start_algo(res);
				free(res);
				return (0);
			}
			return (84);
		}
	}
	err(SYNTAX);
	return (84);
}
