/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:32:22 by seykim            #+#    #+#             */
/*   Updated: 2023/10/26 18:02:53 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook	new_book;
	std::string	arr;

	while (1)
	{
		std::cout << "명령어를 입력해주세요(ADD, EXIT, SERACH) :";
		std::cin >> arr;
		if (arr == "ADD" || arr == "add")
			new_book.phone_add();
		else if (arr == "EXIT" || arr == "exit")
			new_book.phone_exit();
		else if (arr == "SEARCH" || arr == "search")
			new_book.phone_search();
		else
			std::cout << "잘못된 커맨드 입력입니다.(ADD, EXIT, SEARCH)" << std::endl;
	}
	return (0);
}