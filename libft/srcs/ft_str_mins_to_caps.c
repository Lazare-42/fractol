/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mins_to_caps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:18:29 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/29 22:59:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_str_mins_to_caps(char *c)
{
	while (*c)
	{
		if (ft_isalpha(*c))
			*c -= 32;
		c++;
	}
}
