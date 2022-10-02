#include "gtest/gtest.h"

extern "C"
{
#include <production.h>
}

class ProductionTest : public ::testing::Test
{
protected:
	void SetUp() override{}
	void TearDown() override{}
};

TEST_F(ProductionTest, FirstTest) {
	// Arange
	//Act
	int n = production_sum(3, 4);

	//Assert/Expect
	EXPECT_EQ(n, 7);
}