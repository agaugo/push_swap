/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 19:37:46 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/14 19:37:46 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	i = 0;
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (s1_cast[i] != '\0' && i < n)
	{
		if (s1_cast[i] > s2_cast[i])
			return (1);
		else if (s1_cast[i] < s2_cast[i])
			return (-1);
		else
			i++;
	}
	if (i != n && s2[i] != '\0')
		return (-1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_duplicates(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strlen(argv[i]) == ft_strlen(argv[j]))
			{
				if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
