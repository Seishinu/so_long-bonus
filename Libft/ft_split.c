/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:08:25 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/19 22:02:10 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **new, int num)
{
	int	i;

	i = 0;
	while (i < num)
		free(new[i++]);
	free (new);
}

static char	**fill(char **new, char *str, char c)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i + j] != c && str[i + j])
			j++;
		new[num] = ft_substr(str, i, j);
		if (!new[num])
		{
			ft_free(new, num);
			return (0);
		}
		i += j;
		num++;
	}
	return (new);
}

static int	cuts(char *str, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		num++;
	}
	return (num);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**new;
	int		num_of_str;

	if (!s)
		return (0);
	str = (char *)s;
	num_of_str = cuts(str, c);
	new = (char **)malloc((num_of_str + 1) * sizeof(char *));
	if (!new)
		return (0);
	new = fill (new, str, c);
	if (new)
		new[num_of_str] = 0;
	return (new);
}
