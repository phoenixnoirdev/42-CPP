/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:31:16 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/07 15:07:49 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount;" << _amount << ";"
				<< "created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount;" << _amount << ";"
		<< "closed\n";
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals 
		<< "\n";
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool conf = false;

	if (withdrawal < _amount)
	{
		conf = true;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}

	_displayTimestamp();
	if (conf == true)
		std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount + withdrawal << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< "\n";
	else
		std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:refused"
		<< "\n";
	return conf;
}

int		Account::checkAmount(void) const
{
	return _totalAmount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< "\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(nullptr);
	std::tm tm_info;

	if (localtime_s(&tm_info, &t) == 0) {
		std::cout << "["
			<< 1900 + tm_info.tm_year
			<< (tm_info.tm_mon < 10 ? "0" : "") << 1 + tm_info.tm_mon
			<< (tm_info.tm_mday < 10 ? "0" : "") <<  tm_info.tm_mday
			<< "_"
			<< (tm_info.tm_hour < 10 ? "0" : "") << tm_info.tm_hour
			<< (tm_info.tm_min < 10 ? "0" : "") << tm_info.tm_min
			<< (tm_info.tm_sec < 10 ? "0" : "") << tm_info.tm_sec
			<< "] ";	
	}
	else {
		std::cerr << "Erreur lors de la conversion du temps." << std::endl;
	}
}
