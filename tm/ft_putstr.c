/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:11:04 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/24 18:23:08 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char const *s)
{
	int		i;
	int len;

	len = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return ;

	while (s[i] != '\0')
	{
		write(len, &s[i], 1);
		i++;
	}
}
