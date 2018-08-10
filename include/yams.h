/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef YAMS_H_
#	define YAMS_H_

#	include <stdio.h>
#	include <string.h>
#	include <stdlib.h>
#	include <unistd.h>

#	define	ERR -1

enum	err_type {
	SYNTAX = 10,
	COMB,
	DVALUE,
	CVALUE
};

enum	comb_type {
	PAIR,
	THREE,
	FOUR,
	FULL,
	STRAIGHT,
	YAMS
};

void		parse(char **argv, int *res);
double		pair(int c, int *dice);
double		three(int c, int *dice);
double		four(int c, int *dice);
double		yams(int c, int *dice);
double		straight(int c, int *dice);
double		full(int c1, int c2, int *dice);
double		fact(double nb);
double		power(double nb, int pow);
int		how_many_right(int c, int *dice);
int		is_done(int c, int *dice, int needed);
void		start_algo(int *res);
double		binomiale(double n, double k);

#endif /* !YAMS_H_ */
