/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:14:33 by seykim            #+#    #+#             */
/*   Updated: 2023/10/24 14:14:33 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
	_nbWithdrawals = 0;
    _nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" 
    << _amount << ";created" << std::endl; 
}

Account::~Account(void)
{
    _nbAccounts--;
	_totalNbDeposits = _totalNbDeposits - _nbDeposits;
	_totalAmount = _totalAmount - _amount;
	_totalNbWithdrawals = _totalNbWithdrawals - _nbWithdrawals;
	
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
    << ";amount:" << _amount 
    << ";closed" << std::endl; 
}

void	Account::_displayTimestamp( void )
{
    time_t  now_time;
    char    buf[16];

    time(&now_time);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&now_time));
    std::cout << "[" << buf << "]";
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
	
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() 
    << ";total:" << getTotalAmount() 
    << ";deposits:" << getNbDeposits() 
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _amount = _amount + deposit;
    _totalAmount = _totalAmount + deposit;
    _nbDeposits++;
	_totalNbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount - deposit
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits
    << std::endl;
}

int		Account::checkAmount( void ) const
{
    if (_amount < 0)
        return (1);
    return (0);
}

bool	Account::makeWithdrawal( int withdrawal )
{
    bool    result;

    _amount = _amount - withdrawal;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount + withdrawal;
    if (checkAmount())
    {
        result = false;
        _amount = _amount + withdrawal;
        std::cout << ";withdrawal:refused" << std::endl;
    }
    else
    {
        result = true;
        _totalAmount = _totalAmount - withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal
        << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals
        << std::endl;
    }
    return (result);
}
