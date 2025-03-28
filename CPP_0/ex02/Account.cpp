#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_amount(initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_totalAmount += checkAmount();
	_displayTimestamp();	
	std::cout  	<< "index:" << this->_accountIndex
				<< ";" <<"amount:" << checkAmount() << ";" << "created" 
				<< std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout  	<< "index:" << this->_accountIndex
				<< ";" <<"amount:" << checkAmount() << ";" << "closed" 
				<< std::endl;
}
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << Account::getNbAccounts() << ";"
				<< "total:" << Account::getTotalAmount() << ";"
				<< "deposits:" << Account::getNbDeposits() << ";"
				<< "Withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout  	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << checkAmount() - deposit << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << checkAmount() << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout  	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << checkAmount() << ";"
				<< "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout 	<< withdrawal << ";"
					<< "amount:" << checkAmount() << ";"
					<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	return (true);
}

int Account::checkAmount(void)const
{
	return (this->_amount);
}

void Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout  	<< "index:" << this->_accountIndex << ";" 
				<<"amount:" << checkAmount() << ";" 
				<<  "deposits:" << this->_nbDeposits << ";" 
				<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::cout << "[20250327_121533] ";	
}