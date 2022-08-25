#pragma once
class BankAccount
{
public:
	BankAccount();

	bool withdraw(int amount);
	void deposit(int amount);
	int getAvailableFunds() const;
private:
	int accountBalance;
};

