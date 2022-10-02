#pragma once

typedef struct account* account_t;

typedef enum {
	ACCOUNT_OK
}account_status_t;

account_t account_create();
double account_balance(account_t self);
account_status_t account_deposit(double amount);
double account_getBalance();


