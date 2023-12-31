#include "../List & Stack/TLCalc.h"

#include "gtest.h"



TEST(TLCalc, can_create_calc_with_right_infix)
{
	TLCalc calc("2+2");
	std::string str = "2+2";
	EXPECT_EQ(1, str == calc.GetInfix());
}

TEST(TLCalc, can_SetInfix)
{
	TLCalc calc("3-3");
	std::string str = "2+2";
	calc.SetInfix(str);
	EXPECT_EQ(1, str == calc.GetInfix());
}

TEST(TLCalc, can_summ)
{
	TLCalc calc("2+2");
	EXPECT_EQ(4, calc.Calc());
}

TEST(TLCalc, can_multiply)
{
	TLCalc calc("2*2");
	EXPECT_EQ(4, calc.Calc());
}

TEST(TLCalc, can_div)
{
	TLCalc calc("2/2");
	EXPECT_EQ(1, calc.Calc());
}

TEST(TLCalc, can_sub)
{
	TLCalc calc("2-2");
	EXPECT_EQ(0, calc.Calc());
}

TEST(TLCalc, can_pow)
{
	TLCalc calc("2^2");
	EXPECT_EQ(4, calc.Calc());
}


TEST(TLCalc, can_correctly_calculate_no_postfix)
{
	TLCalc calc("2^2+2*3-(1+2/2)");
	EXPECT_EQ(8, calc.Calc());
}

TEST(TLCalc, can_correctly_calculate_long)
{
	TLCalc calc("(2^2+2*3-(1+2/2)-100-(32-22))^2-0.1");
	EXPECT_EQ(10403.9, calc.Calc());
}



