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
	std::cout  	<< "index:" << "\033[34m" << this->_accountIndex << "\033[0m" 
				<< ";" <<"amount:" << "\033[34m" << checkAmount() << "\033[0m" 
				<< ";" << "created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout  	<< "index:" << "\033[34m" << this->_accountIndex << "\033[0m" 
				<< ";" <<"amount:" << "\033[34m" << checkAmount() << "\033[0m" 
				<< ";" << "closed" << std::endl;
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
	std::cout 	<< "accounts:" << "\033[34m" << Account::getNbAccounts() << "\033[0m" << ";"
				<< "total:" << "\033[34m" << Account::getTotalAmount() << "\033[0m" << ";"
				<< "deposits:" << "\033[34m" << Account::getNbDeposits() << "\033[0m" << ";"
				<< "Withdrawals:" << "\033[34m" << Account::getNbWithdrawals() << "\033[0m" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout  	<< "index:" << "\033[34m" << this->_accountIndex << "\033[0m" << ";"
				<< "p_amount:" << "\033[34m" << checkAmount() - deposit << "\033[0m" << ";"
				<< "deposit:" << "\033[34m"<< deposit << "\033[0m" << ";"
				<< "amount:" << "\033[34m"<< checkAmount() << "\033[0m" << ";"
				<< "nb_deposits:"<< "\033[34m" << _nbDeposits << "\033[0m" << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout  	<< "index:" << "\033[34m" << this->_accountIndex << "\033[0m" << ";"
				<< "p_amount:" << "\033[34m" << checkAmount() << "\033[0m" << ";"
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
		std::cout 	<< "\033[34m" << withdrawal << "\033[0m" <<  ";"
					<< "amount:" << "\033[34m" << checkAmount() << "\033[0m" <<  ";"
					<< "nb_withdrawals:" << "\033[34m" << _nbWithdrawals << "\033[0m" << std::endl;
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
	std::cout  	<< "index:" << "\033[34m" << this->_accountIndex << "\033[0m" << ";" 
				<<"amount:" << "\033[34m" << checkAmount() << "\033[0m" << ";" 
				<<  "deposits:" << "\033[34m" << this->_nbDeposits << "\033[0m" << ";" 
				<< "withdrawals:" << "\033[34m" << this->_nbWithdrawals << "\033[0m" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::cout << "[20250327_121533] ";	
}