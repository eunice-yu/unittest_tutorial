// 	memory, timeout =>  non functional test

#include "gtest/gtest.h"
#include <unistd.h>
#include <time.h>

// CRTP : Curiosly Recurring Template Pattern
// => parent class is parent and it pass over its owntype as parameter when interited
// 	to make each class diffent type (sicne it shares static variable)

template <typename T, int N>
class TimeoutTest : public ::testing::Test{
    static const int PIVOT = N;
protected:
    time_t startTime;
    void SetUp(){
        startTime = time(0);
    }

    void TearDown(){
        time_t endTime = time(0);
        time_t duration = endTime - startTime;

        EXPECT_TRUE(duration < PIVOT) <<"time out-"<<duration<<"sec";
    }
};

class MyTest: public TimeoutTest<MyTest, 4>{
};

class TwoSecondsTimeoutTest : public TimeoutTest<TwoSecondsTimeoutTest, 2>{
};

TEST_F(TwoSecondsTimeoutTest, foo){
	sleep(3);
}

TEST_F(MyTest, foo2){
	sleep(3);
}
