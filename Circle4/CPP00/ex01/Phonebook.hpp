/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:30:25 by seykim            #+#    #+#             */
/*   Updated: 2023/10/26 17:51:23 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
private:
	int		PhoneNum;
	int		OldestNum;
	Contact	Contact[8];
public:
	Phonebook(void);
	void	phone_exit(void);
	void	phone_add(void);
	void	phone_search(void);
	void	print_index(void);
	void	cin_error_check(void);
	void	SetOldestNum(int num);
	void	SetPhoneNum(int num);
};

#endif