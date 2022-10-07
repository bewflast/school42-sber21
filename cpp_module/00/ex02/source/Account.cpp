#include "../include/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts            =   0;
int Account::_totalAmount           =   0;
int Account::_totalNbDeposits       =   0;
int Account::_totalNbWithdrawals    =   0;

void Account::_displayTimestamp( void )
{
    time_t  temp = std::time(NULL);

    std::cout << std::put_time(std::localtime(&temp), "[%Y%m%d_%H%M%S] ");
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    t::_displayTimestamp();

    std::cout   <<  "accounts:"     << t::getNbAccounts()     <<  ";" <<  \
                    "total:"        << t::getTotalAmount()    <<  ";" <<  \
                    "deposits:"     << t::getNbDeposits()     <<  ";" <<  \
                    "withdrawals:"  << t::getNbWithdrawals()  <<  std::endl;
}

int Account::checkAmount( void ) const
{
    return (this->_amount);
}

Account::Account( int initial_deposit )
{
    t::_totalAmount       += initial_deposit;

    this->_amount               += initial_deposit;
    this->_accountIndex         = t::_nbAccounts++;

    t::_displayTimestamp();
    std::cout   <<  "index:"    <<  this->_accountIndex <<  ";" <<  \
                    "amount:"   <<  this->checkAmount() <<  ";" <<  \
                    "created"   <<  std::endl;
}

void Account::makeDeposit( int deposit )
{
    this->_amount               += deposit;
    this->_nbDeposits++;

    t::_totalAmount       += deposit;
    t::_totalNbDeposits++;   

    t::_displayTimestamp();
    std::cout   <<  "index:"        <<  this->_accountIndex             <<  ";" <<  \
                    "p_amount:"     <<  (this->_amount - deposit)       <<  ";" <<  \
                    "deposit:"      <<  deposit                         <<  ";" <<  \
                    "amount:"       <<  this->checkAmount()             <<  ";" <<  \
                    "nb_deposits:"  <<  this->_nbDeposits               <<  std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    t::_displayTimestamp();
    std::cout   <<  "index:"    <<  this->_accountIndex <<  ";" <<  \
                    "p_amount:" <<  this->checkAmount()       <<  ";" <<  \
                    "withdrawal:";
    
    if (withdrawal > this->checkAmount())
    {
        std::cout   <<  "refused"   <<  std::endl;
        return (false);
    }

    t::_totalAmount         -= withdrawal;
    t::_totalNbWithdrawals++;

    this->_amount           -= withdrawal;
    this->_nbWithdrawals++;

    std::cout   <<  withdrawal          <<                              ";" <<  \
                    "amount:"           <<  this->checkAmount()     <<  ";" <<  \
                    "nb_withdrawals:"   <<  this->_nbWithdrawals    <<  std::endl;

    return (true);
}

void Account::displayStatus( void ) const
{
    t::_displayTimestamp();
    std::cout   <<  "index:"        <<  this->_accountIndex <<  ";" <<  \
                    "amount:"       <<  this->checkAmount() <<  ";" <<  \
                    "deposits:"     <<  this->_nbDeposits   <<  ";" <<  \
                    "withdrawals:"  <<  this->_nbWithdrawals    <<  ";" <<  std::endl;
}

Account::~Account()
{
    t::_displayTimestamp();
    std::cout   <<  "index:"    <<  this->_accountIndex <<  ";" <<  \
                    "amount:"   <<  this->checkAmount() <<  ";" <<  \
                    "closed"    <<  std::endl;
}