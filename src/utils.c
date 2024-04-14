/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeha <daeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:23:00 by daeha             #+#    #+#             */
/*   Updated: 2024/04/01 18:37:00 by daeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	terminate(void)
{
	write(2, "Error\n", 6);
	exit(1);
}