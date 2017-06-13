class Calculator {
	int value;
public:
	Calculator( int n ):value(n){}

	void plus(int n) { value +=n; }
	void minus(int n) { value -=n; }
	int display(){ return value;}
};

/////////////////////////////////////////

#include <gtest/gtest.h>
// Fixture setup 1
// create object in each Test
// => Code redundancy

#if 0
TEST(CalculatorTest, plusTest)
{
	Calculator *calculator = new Calculator;

	calculator->plus(2);
	calculator->plus(2);

	ASSERT_EQ(4 , calculator->display()) <<"2+2";
	delete calculator;
}

TEST(CalculatorTest, minusTest)
{
	Calculator *calculator = new Calculator;

	calculator->minus(2);
	calculator->minus(2);

	ASSERT_EQ(-4 , calculator->display()) <<"-2-2";
	delete calulator;
}
#endif


// Fixture setup 2
// 1. collect test function as class who has the same fixture
//      => Testcase class
// 2. provide a fucntion for fixture setup

#if 0
class CalculatorTest : public ::testing::Test{
    // a visibility of test utility method should be 'protected'
	// since this should be accessed from Test fixture
protected:
    // creatio method
    // easier to fix object construction
    Calculator* create(){
        return new Calculator(0);
    }
};

TEST_F(CalculatorTest, plugTest)
{
	Calculator *calculator = create(0);

	calculator->plus(2);
	calculator->plus(2);

	ASSERT_EQ(4 , calculator->display()) <<"2+2";
}

TEST(CalculatorTest, minusTest)
{
	Calculator *calculator = create(0);

	calculator->minus(2);
	calculator->minus(2);

	ASSERT_EQ(-4 , calculator->display()) <<"-2-2";
}
#endif

// Fixtuer setup 3 - Implicit setup
// setup fixture inside setup() function which is provided by xUnit Test Framework
// ==> remove code redundency, can encapsulated non necessary codes

#include <stdio.h>
#include <memory>
using namespace std;


class CalculatorFTest: public::testing::Test{
public :
	CalculatorFTest(){
		printf("CalculatorTest()\n");
	}
protected:
    shared_ptr<Calculator> calculator;
    //same as @Before / @BeforeEach in jUnit
    virtual void SetUp(){
        printf("Setup()\n");
        calculator = make_shared<Calculator>(0);
    }

    //same as @After / @AfterEach in Junit
    virtual void TearDown(){
        printf("TearDown()\n");
    }
};

TEST_F(CalculatorFTest, plusTest)
{
    printf("plusTes\n");
	calculator->plus(2);
	calculator->plus(2);

	ASSERT_EQ(4 , calculator->display()) <<"2+2";
}

TEST_F(CalculatorFTest, minusTest)
{
    printf("minuxTest\n");
	calculator->minus(2);
	calculator->minus(2);

	ASSERT_EQ(-4 , calculator->display()) <<"-2-2";
}

