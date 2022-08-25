#include "pch.h"

#include "../Basic/Calculator.h"

TEST(CalculatorTest, Sum2plus2equals4) {
	Calculator calc;

	EXPECT_EQ(calc.sum(2, 2), 4);
}
