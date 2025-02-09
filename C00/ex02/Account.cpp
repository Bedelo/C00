/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:18:23 by bsunda            #+#    #+#             */
/*   Updated: 2025/02/09 10:50:57 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ){
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);

	std::ostringstream oss;
	oss << "[" 
		<< (1900 + ltm->tm_year) // Année
		<< std::setw(2) << std::setfill('0') << (1 + ltm->tm_mon) // Mois
		<< std::setw(2) << std::setfill('0') << ltm->tm_mday // Jour
		<< "_"
		<< std::setw(2) << std::setfill('0') << ltm->tm_hour // Heure
		<< std::setw(2) << std::setfill('0') << ltm->tm_min // Minutes
		<< std::setw(2) << std::setfill('0') << ltm->tm_sec // Secondes
		<< "]";

	std::cout << oss.str();
}

Account::Account( void ){
	return ;
}

Account::Account( int initial_deposit ){
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ){
	return _nbAccounts;
}

int	Account::getTotalAmount( void ){
	return _totalAmount;
}

int	Account::getNbDeposits( void ){
	return _totalNbDeposits;	
}

int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit; 
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount){
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const{
	return this->_amount ;
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}