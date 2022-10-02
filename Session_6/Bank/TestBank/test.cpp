#include <gtest/gtest.h>

extern "C"
{
	#include <account.h>
}

TEST(AccountTest, BalanceIsZeroWhenAccountCreate) {
	account_t uut = account_create();
  EXPECT_EQ(0, account_balance(uut));
}

TEST(AccountTest, PostiveDepositIsAllowed)
{
	account_t uut = account_create();

	account_status_t rc = account_deposit(1.0);

	EXPECT_EQ(ACCOUNT_OK, rc);
}

TEST(AccountTest, BalanceIsIncreacedWithDepositAmount)
{
	account_t uut = account_create();

	account_status_t rc = account_deposit(1.0);

	EXPECT_DOUBLE_EQ(1.0, account_balance);
}