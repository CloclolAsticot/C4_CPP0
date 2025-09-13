/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:12:00 by csavreux          #+#    #+#             */
/*   Updated: 2025/08/30 17:23:03 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void shout_arg(char *arg)
{
	while (*arg != '\0')
	{
		std::cout << static_cast<char>(std::toupper(*arg));
		arg++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	av++;
	while (*av != NULL)
	{
		shout_arg(*av);
		av++;
	}
	std::cout << std::endl;
	return 0;
}
