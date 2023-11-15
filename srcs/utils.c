/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 09:26:21 by lex               #+#    #+#             */
/*   Updated: 2023/10/06 11:30:56 by lex              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_putnbr(int n)
{
	char c;
	long nnbr;

	nnbr = n;
	if (nnbr < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nnbr *= -1;
	}
	if (nnbr != 0)
	{
		if (nnbr / 10 > 0)
			ft_putnbr(nnbr / 10);
		c = nnbr % 10 + 48;
		write(STDOUT_FILENO, &c, 1);
	}
	if (n == 0)
		write(STDOUT_FILENO, "0", 1);
}


// int	ft_atoi(const char *str)
// {
// 	int				i;
// 	long long int	numb;
// 	int				sign;

// 	i = 0;
// 	sign = 1;
// 	numb = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
// 		i++;
// 	if (str[i] == '-')
// 		sign = -1;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		numb = numb * 10 + (str[i] - '0');
// 		if (numb < 0 && sign == -1 && numb != -2147483648)
// 			return (0);
// 		if (numb < 0 && sign == 1)
// 			return (-1);
// 		i++;
// 	}
// 	return (numb * sign);
// }

int				ft_atoi(const char *str, int *num)
{
	char	*ptr;
	long	nbr;
	int		sign;
	size_t	i;

	ptr = (char *)str;
	nbr = 0;
	sign = 1;
	if (*ptr == '-' && ptr++)
		sign *= -1;
	if (*ptr == '\0')
		return (1);
	i = 0;
	while (*ptr >= '0' && *ptr <= '9' && i++ < 10)
		nbr = nbr * 10 + *ptr++ - '0';
	if (*ptr != '\0' || nbr * sign > 2147483647 || nbr * sign < -2147483648)
		return (1);
	*num = nbr * sign;
	return (0);
}