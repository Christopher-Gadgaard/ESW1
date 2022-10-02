#include "Account.h"
#include<stdlib.h>


typedef struct account {
	int accountNo;
	double creditLimit;
	double balance;
}account_st_t;

account_t account_create(int accountNo, double creditLimit)
{
	account_t _newAccount = calloc(sizeof(account_st_t), 1);

	if (NULL == _newAccount)
	{
		return NULL;
	}

	_newAccount->accountNo = accountNo;
	_newAccount->creditLimit = creditLimit;

	return _newAccount;
}

void account_destroy(account_t self)
{
	if (NULL != self)
	{
		free(self);
	}
}

account_accountStatus_t account_withdraw(account_t self, double amount)
{
	if (self == NULL)
	{
		return ACCOUNT_NOT_INSTANTIANTED;
	}

	if (amount < self->balance+self->creditLimit)
	{
		self->balance -= amount;
		return OK;
	}

	return OVER_MAX_CREDIT_LIMIT;
}

account_accountStatus_t account_deposit(account_t self, double amount)
{
	if (self == NULL)
	{
		ACCOUNT_NOT_INSTANTIANTED;
	}

	self->balance += amount;
	return OK;
}

double account_getBalance(account_t self)
{
	return self->balance;
}
double account_getCreditLimit(account_t self)
{
	return self->creditLimit;
}
int account_getAccountNo(account_t self)
{
	return self->accountNo;
}