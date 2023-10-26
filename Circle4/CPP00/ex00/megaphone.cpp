/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:18:41 by seykim            #+#    #+#             */
/*   Updated: 2023/10/26 13:32:30 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string argumentCopy = argv[i];
			for (size_t i = 0; i < argumentCopy.length(); i++)
            	argumentCopy[i] = std::toupper(argumentCopy[i]);
			std::cout << argumentCopy;
		}
		std::cout<<std::endl;
	}
}
