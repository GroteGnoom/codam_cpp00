#include "Account.hpp"
#include <iostream>
#include <ctime>
// the constructor prints out creation, destructor prints out closed

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals= 0;

void Account::_displayTimestamp() {
	char buffer[100];
	time_t t1;
	time(&t1);
	struct tm *t = localtime(&t1);
	strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", t);
	std::cout << buffer;
}

Account::Account(int a) {
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_accountIndex = _nbAccounts;
	_amount = a;
	_totalAmount += a;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
		";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
		";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts++;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int a)
{
	_totalAmount += a;
	_totalNbDeposits++;

	_amount += a;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount - a << ";deposit:" << a
		<< ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int a)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount << ";withdrawal:";
	if (_amount >= a) {
		_totalAmount -= a;
		_totalNbWithdrawals++;


		_amount -= a;
		_nbWithdrawals++;
		std::cout << a << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int	Account::checkAmount(void) const {
	return (_amount);
}



