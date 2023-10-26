/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:32:11 by seykim            #+#    #+#             */
/*   Updated: 2023/10/26 17:53:14 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	Phonebook::phone_exit(void)
{
	std::cout << "종료" << std::endl;
	exit(1);
}

void	Phonebook::phone_add(void)
{
	if (this->PhoneNum < 8)
	{
		this->Contact[PhoneNum % 8].addcontact();
		SetPhoneNum(this->PhoneNum + 1);
	}
	else
	{
		SetOldestNum(this->OldestNum % 8);
		this->Contact[OldestNum % 8].addcontact();
		SetOldestNum(this->OldestNum + 1);
	}
}

Phonebook::Phonebook(void)
{
	OldestNum = 0;
	PhoneNum = 0;
}

void	Phonebook::SetOldestNum(int num)
{
	this->OldestNum = num;
}

void	Phonebook::SetPhoneNum(int num)
{
	this->PhoneNum = num;
}

void	Phonebook::print_index(void)
{
	for (int i = 0; i < this->PhoneNum; i++)
	{
		std::cout << std::setw(9);
		std::cout << i + 1;
		this->Contact[i].contact_search();
	}
}

void	Phonebook::cin_error_check(void)
{
	int num;

	std::cout << "원하는 번호를 입력하세요 :"; 
	std::cin >> num;
	// cin 입력이 실패했을 때
	// int가 아니거나, 범위를 벗어났을 때
	if (std::cin.fail())
	{
		std::cin.clear(); // cin버퍼를 비워줌, 하지만 개행문자는 남아있음
		std::cin.ignore(255, '\n'); // 전체입력부터 개행까지의 문자를 제거
		std::cout << "잘못된 입력입니다." << std::endl;
	}
	else
	{
		num -= 1;
		if (num >= 0 && num <= 7 && num < this->PhoneNum)
			Contact[num].print_selcet();
		else
			std::cout << "잘못된 입력입니다." << std::endl;
	}
}

void	Phonebook::phone_search(void)
{
	if (this->PhoneNum == 0)
		std::cout << "저장된 연락처가 없습니다." << std::endl;
	else
	{
		// 조건에 맞게 출력
		std::cout << "index " << "|" << " first name " << "|" << " last name " << "|" << " nickname" << "|" << std::endl;
		print_index();
		// 선택된 번호 전체 출력
		cin_error_check();
	}
}
