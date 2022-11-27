#include "gtest/gtest.h"
#include "../../../../fff/fff.h"
DEFINE_FFF_GLOBALS

extern "C"
{
#include "HAL.h"
#include "Production.h"
}

FAKE_VOID_FUNC(HAL_create, uint8_t);
FAKE_VALUE_FUNC(int16_t, HAL_getVoltage, uint8_t);

class ProductionCodeTestFFF : public ::testing::Test {
protected:
	void SetUp() override
	{
		RESET_FAKE(HAL_create);
		RESET_FAKE(HAL_getVoltage);
		FFF_RESET_HISTORY();
	}
};

TEST_F(ProductionCodeTestFFF, Test_HAL_create_is_called_and_temperature_calculated_correct)
{
	production_create();

	ASSERT_EQ(HAL_create_fake.call_count, 1);
	ASSERT_EQ(HAL_create_fake.arg0_val, 10);
}

TEST_F(ProductionCodeTestFFF, Test_HAL_getVolatage_is_called)
{
	uint8_t _sensor = 12;
	HAL_getVoltage_fake.return_val = 15;

	production_messureTemperature(_sensor);
	int8_t _temp = production_getTemperature(_sensor);

	ASSERT_EQ(HAL_getVoltage_fake.call_count, 1);
	ASSERT_EQ(HAL_getVoltage_fake.arg0_val, _sensor);

	ASSERT_EQ(_temp, 15 * 2);
}