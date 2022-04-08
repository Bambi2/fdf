/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:52 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/08 21:47:35 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (fdf(argv[1]))
			return (0);
	}
	else
		ft_putstr_fd("Wrong number of arguments\n", 2);
	return (1);
}
