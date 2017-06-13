// Google Test Functionality

#include "gtest/gtest.h"
using namespace std;

class Resource {};
// Assert statement (ASSERT_XX / EXPECT_XX)
// : if fails, rest of the codes are not executed - ASSERT_XX
// : rest of the codes are executed even it fails - EXPECTED_XX
// disable test
// start the test case with DISABLED_
// @Ignore - jUnit4
// @Disable - jUnit5

TEST(GoogleTest, DISABLED_function1)
{
	int expected =42;
    Resource *res = new Resource;

    EXPECT_EQ(expected, 40);
    EXPECT_EQ(expected, 30);

	ASSERT_EQ(expected, 40);
	ASSERT_EQ(expected, 30);

    delete res;
}

#include <string>

TEST(GoogleTest, function2)
{
    string s1="hello";
    string s2="hello";

    ASSERT_EQ(s1, s2); // operator == (const T& l , const T& r)

    //in comparison string if const char* is used you canot use ASSERT_EQ

    const char* s3 = "hello";
    const char* s4 = s2.c_str();
    //EXPECT_EQ(s3, s4); // s3 s2 is not equal
    ASSERT_STREQ(s3, s4);
}

// ASSERT_DOUBLE_EQ ASSERT_FLOAT_EQ, ASSERT_NEAR
TEST(GoogleTest, function3)
{
    //ASSERT_EQ(0.7, 0.1*7);
    ASSERT_DOUBLE_EQ(0.7, 0.1*7);

    ASSERT_NEAR(0.7, 0.1*7, 0.000000001);
}


void foo(const string& name)
{
    if(name.empty())
        throw invalid_argument("name should not empty");
    //,,,
}

// 5. exception test
// :check if  foo function gets invalid argment
TEST(GoogleTest, function4)
{
    string bad_name ="";
    try{
        foo(bad_name);
        FAIL() <<"no exception occured";
    } catch(invalid_argument&){
        SUCCEED();
    } catch(...){
        FAIL() <<"not an expected exception";
    }
}

TEST(GoogleTest, function5) {
    string bad_name ="";
    ASSERT_THROW(foo(bad_name) , invalid_argument);
}

//EQ LT GT LE GE
