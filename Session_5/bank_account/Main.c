#include "account.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static account_t accounts[11];

static void _delayMs(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

static int getRandom(int lower, int upper)
{
	return rand() % (upper + 1 - lower) + lower;
}

static void _createAccounts()
{
	for (int i = 0; i <= 10; i++)
	{
		accounts[i] = account_create(getRandom(1000, 9999), 500.0);
	}
}

static void _makeRandomTransaction()
{
	int accountIndex = getRandom(0, 10);
	int amount = getRandom(1, 750);

	if (getRandom(0, 1))
	{
		printf("Withdrawing from account %d with accNo %d and balance %f the amount %d\n",
			accountIndex,
			account_getAccountNo(accounts[accountIndex]),
			account_getBalance(accounts[accountIndex]),
			amount);

		printf("Response %d\n",
			account_withdraw(accounts[accountIndex], amount));

		printf("New balance %f\n\n", account_getBalance(accounts[accountIndex]));

		return;
	}

	printf("Depositing to account %d with accNo %d and balance %f the amount %d\n",
		accountIndex,
		account_getAccountNo(accounts[accountIndex]),
		account_getBalance(accounts[accountIndex]),
		amount);

	printf("Response %d\n",
		account_deposit(accounts[accountIndex], amount));

	printf("New balance %f\n\n", account_getBalance(accounts[accountIndex]));
}

int main(void)
{
	_createAccounts();
	while (1)
	{
		_makeRandomTransaction();
		_delayMs(1000);
	}

	return 0;
}