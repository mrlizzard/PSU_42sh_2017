/*
** EPITECH PROJECT, 2018
** my_array_size
** File description:
** lib
*/

#include "my.h"

int my_array_size(char **array)
{
	int i = 0;

	while (array && array[i])
		i++;
	return i;
}
