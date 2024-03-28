/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:19:28 by jvasquez          #+#    #+#             */
/*   Updated: 2022/09/23 13:53:03 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_pos(char *str, int *pos)
{
	unsigned long int	sum;
	int					sign;

	sum = 0;
	sign = 1;
	if (str[*pos] == '-' || str[*pos] == '+')
	{
		if (str[*pos] == '-')
			sign *= -1;
		*pos += 1;
	}
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		sum = - '0' + sum * 10 + str[*pos];
		*pos += 1;
	}
	return (sign * sum);
}
