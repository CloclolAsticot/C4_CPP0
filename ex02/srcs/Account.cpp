/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:48:31 by csavreux          #+#    #+#             */
/*   Updated: 2025/11/22 14:04:53 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm* local_time = std::localtime(&now);
    std::cout   << "["
                << local_time->tm_year + 1900
                << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1
                << std::setfill('0') << std::setw(2) << local_time->tm_mday
                << "_"
                << std::setfill('0') << std::setw(2) << local_time->tm_hour
                << std::setfill('0') << std::setw(2) << local_time->tm_min
                << std::setfill('0') << std::setw(2) << local_time->tm_sec
                << "]";
}

// All Account instances
    
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
    std::cout << " accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Current Account instance
    
Account::Account( int initial_deposit )
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
    _totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}
    
Account::~Account( void )
{
    _nbAccounts--;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}
    
void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:";
    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal << ";";
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "amount:" << this->_amount << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}
    
int		Account::checkAmount( void ) const
{
    return (this->_amount);
}
    
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
