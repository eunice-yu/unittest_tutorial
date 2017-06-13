#include <gtest/gtest.h>

class Calculator {
	int value;
public:
	Calculator():value(0){}

	void plus(int n) { value +=n; }
	void minus(int n) { value -=n; }
	int display(){ return value;}
};

// in real test code above code is usually include product header
//#include "Calculator.h"

TEST(CalculatorTest, plus_AddingTwoPlusTwogTest_DisplayFour)
{
	//Arrange(Given)
	Calculator *calculator = new Calculator;

	//Act(When)
	calculator->plus(2);
	calculator->plus(2);

	//Assert(Then)
	//1. encapsulate conditional check
	//2. if there is no spported assert, make your own assert macro
	//3. the order of parameter should be fixed as (Expectation, result)

	//if (calculator->display()!=4)
	//	FAIL() << "2+2=4";
	//==> refactor Test smell: loop, conditional statement, exception handling inside TEST
	ASSERT_EQ(4 , calculator->display()) <<"2+2";
}
