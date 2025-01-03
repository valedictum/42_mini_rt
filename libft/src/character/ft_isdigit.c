/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:46:28 by tday              #+#    #+#             */
/*   Updated: 2024/11/08 19:34:54 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if the given character is an numerical character.

	Inputs
	c = character (int variable as it uses ascii).

	Outputs
	true if the character is numerical, false if it's not.
*/
bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}
