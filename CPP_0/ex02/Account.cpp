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
	_totalAmount +=_amount;	
	std::cout << "[20250327_121533] " << "index:" << this->_accountIndex
				<< ";" <<"amount:" << this->_amount << ";" << "created" 
				<< std::endl;
}
Account::~Account(void)
{
	_nbAccounts--;
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

}
bool Account::makeWithdrawal(int withdrawal)
{
	return (true);
}

int Account::checkAmount(void)const
{
	return (0);
}

void Account::displayStatus(void)const
{

}

void Account::_displayTimestamp(void)
{
	std::cout << "[20250327_121533] ";	
}