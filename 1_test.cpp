#include <stdio.h>
#include "gtest/gtest.h"

TEST(TestCase, Test)
{
	//unfinished testcase must fail!
    //if failed, the reason must be shown
	FAIL() << "in writing...\n";

}

// main function is not usualy changed, so below code canbe be included in static library
/*
int main( int argc, char** argv)
{
	//Google Test library initialization
	::testing::InitGoogleTest(&argc, argv);

	printf ("hello, google test\n");
	return RUN_ALL_TESTS();
}
*/
