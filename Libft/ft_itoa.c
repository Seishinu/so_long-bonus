/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:02:22 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/18 22:39:47 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*filler(int n, char *new, int i)
{
	while (n)
	{
		new[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (new);
}

static int	counting(int num)
{
	int	count;

	count = 0;
	while (num)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = counting(n);
	if (n < 0)
		i++;
	new = (char *)malloc(i + 1);
	if (!new)
		return (0);
	new[i--] = '\0';
	if (n < 0)
	{
		new[0] = '-';
		n = n * (-1);
	}
	return (filler(n, new, i));
}
