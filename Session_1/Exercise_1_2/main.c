#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */

#define max_accounts 10

typedef struct account* account_t;

typedef struct account
{
	int accountNo;
	double cl;
	double bl;
} account_st_t;

void pAD(account_t account)
{
	printf("ano: %d", account->accountNo);
}

main()
{
	account_st_t ca[max_accounts];
	account_t pAccount = NULL;

	for (int i = 0; i < max_accounts; i++)
	{

	}
	pAccount = ca;
	pAD(pAccount + 1);
}