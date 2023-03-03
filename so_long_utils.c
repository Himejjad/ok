/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 03:10:52 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 19:07:07 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i + 1] == '\0' && s[i] != c))
			x++;
		i++;
	}
	return (x);
}

int	count_caracters(const char *s, char c, size_t pos)
{
	int	i;

	i = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		pos++;
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**new;
	size_t	co;
	size_t	i;
	size_t	pos;
	size_t	x;

	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	x = count_word(s, c);
	new = malloc(sizeof(char *) * (x + 1));
	if (!new)
		return (NULL);
	new[x] = NULL;
	while (i < x)
	{
		while (s[pos] == c)
			pos++;
		co = count_caracters(s, c, pos);
		new[i] = ft_substr(s, pos, co);
		pos += co;
		i++;
	}
	return (new);
}

void	check_char(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->maps[i])
	{
		while (j < so_long->width)
		{
			if (so_long->maps[i][j] == 'P')
				so_long->player++;
			else if (so_long->maps[i][j] == 'E')
				so_long->exit++;
			else if (so_long->maps[i][j] == 'C')
				so_long->collect++;
			else if (so_long->maps[i][j] != '1' && so_long->maps[i][j] != '0')
				error();
			j++;
		}
		i++;
		j = 0;
	}
	if (so_long->player != 1 || so_long->exit != 1 || so_long->collect < 1)
		error();
}
