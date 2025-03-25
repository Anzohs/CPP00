#include "Account.hpp"
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_accountIndex = Account::_nbAccounts;
	_nbAccounts++;
	this->_nbDeposits = 0;
	_totalNbDeposits += this->_nbDeposits;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
}

Account::Account(void)
{
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
}

Account::~Account(){
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	if (this->_accountIndex < 7)
			std::cout << std::endl;
}

void Account::makeDeposit(int Deposit)
{
	_totalAmount += Deposit;
	this->_amount += Deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused"  << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::checkAmount( void ) const{
	return (this->_amount);
}

int Account::getNbAccounts(void)
{return (_nbAccounts);}

int	Account::getTotalAmount(void)
{return (_totalAmount);}

int Account::getNbDeposits(void)
{return (_totalNbDeposits);}

int Account::getNbWithdrawals(void)
{return (_totalNbWithdrawals);}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		actual_time;
	struct tm	*timeinfo;

	time(&actual_time);

	timeinfo = localtime(&actual_time);
	std::cout << "[" << timeinfo->tm_year + 1900;
	std::cout.fill('0');
	std::cout.width(2);
	std::cout << timeinfo->tm_mon;
	std::cout.width(2);
	std::cout << timeinfo->tm_mday << "_";
	std::cout.width(2);
	std::cout << timeinfo->tm_hour;
	std::cout.width(2);
	std::cout << timeinfo->tm_min;
	std::cout.width(2);
	std::cout << timeinfo->tm_sec << "] ";
	std::cout.fill(' ');
}
