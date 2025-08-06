/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:19:49 by nqasem            #+#    #+#             */
/*   Updated: 2025/08/06 16:45:27 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void )
{
	time_t now = std::time(0);
	struct tm *ltm = std::localtime(&now);
	char			log_time[19];

	std::strftime (log_time, 19, "[%G%m%d_%H%M%S] ", ltm);
	std::cout << log_time;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << "; amount:" << _amount
			  << "; created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << "; amount:" << _amount	
			  << "; closed" << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
			  << "; total:" << getTotalAmount()
			  << "; deposits:" << getNbDeposits()
			  << "; withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << " index:" << _accountIndex
			  << "; p_amount:" << _amount - deposit
			  << "; deposit:" << deposit
			  << "; amount:" << _amount
			  << "; nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << " index:" << _accountIndex
				  << "; p_amount:" << _amount
				  << "; withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << " index:" << _accountIndex
			  << "; p_amount:" << _amount + withdrawal
			  << "; withdrawal:" << withdrawal
			  << "; amount:" << _amount
			  << "; nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}
int	Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << "; amount:" << _amount
			  << "; deposits:" << _nbDeposits
			  << "; withdrawals:" << _nbWithdrawals << std::endl;
}
