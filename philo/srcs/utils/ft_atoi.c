/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:53:47 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/12 13:54:27 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_overflow(int signe)
{
	if (signe < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				negatif;
	long long int	total;

	negatif = 1;
	total = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negatif *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
		if (total != ((total * 10) + *str - '0') / 10)
			return (ft_overflow(negatif));
		total = (total * 10) + *str - '0';
		str++;
	}
	return (negatif * total);
}
