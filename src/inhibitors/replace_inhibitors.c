/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include "42.h"

static char	*get_inhibitor(void)
{
	char	*buffer = NULL;

	my_putstr(">");
	buffer = get_next_line(0);
	return buffer;
}

static char	*replace_inhibitor(char *cmd, char *inhibitor)
{
	int	i = 0;
	int	j = 0;
	int	len = my_strlen(cmd) + my_strlen(inhibitor);
	char	*new = malloc(sizeof(char) * (len + 1));

	while (i < len - 2) {
		if (cmd[i] == '\\') {
			for (; inhibitor && inhibitor[j]; j++) {
				new[i] = inhibitor[j];
				i++;
			}
		} else {
			new[i] = cmd[i];
			i++;
		}
	}
	new[i] = '\0';
	return new;
}

void	change_cmd_inhibitors(parser_t **b_tree, char *cmd)
{
	parser_t	*tmp = *b_tree;
	char		*inhibitor = get_inhibitor();

	while (tmp) {
		if (my_strcmp(tmp->full_cmd, cmd) == 0) {
			tmp->full_cmd = replace_inhibitor(tmp->full_cmd,
				inhibitor);
		}
		tmp = tmp->next;
	}
	free(inhibitor);
}