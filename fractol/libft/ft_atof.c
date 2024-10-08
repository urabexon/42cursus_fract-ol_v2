/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:42:49 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/08 21:47:03 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	nmb;
	int		power;

	nmb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		nmb = nmb * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	power = 1;
	while (ft_isdigit(*str))
	{
		nmb = nmb * 10 + (*str++ - '0');
		power *= 10;
	}
	return (sign * nmb / power);
}
