#include "BankAccount.h"

BankAccount::BankAccount()
	: accountBalance(0)
{

}

bool BankAccount::withdraw(int amount)
{
	if (amount > accountBalance)
	{
		return false;
	}
	else
	{
		accountBalance -= amount;
		return true;
	}
}

void BankAccount::deposit(int amount)
{
	accountBalance += amount;
}

int BankAccount::getAvailableFunds() const
{
	return accountBalance;
}