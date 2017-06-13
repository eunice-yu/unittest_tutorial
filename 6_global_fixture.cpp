// SetUp when program starts
// TearDown when Program ends

#include "gtest/gtest.h"

class TestEnvironment: public ::testing::Environment {
public:
	void SetUp(){
		printf("Global Setup\n");
	}

	void TearDown(){
		printf("Global TearDown\n");
	}
};


TEST(SampleTest,foo){
    printf("test foo\n");
}

// 1. global variable => when using gtest_main.cc
::testing::Environment* const env
	= ::testing::AddGlobalTestEnvironment(new TestEnvironment);


// 2. add env in main function => whennot using gtest_main.cc
// 		==> preffered way
#if 0
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::Environment* const env
	    = ::testing::AddGlobalTestEnvironment(new TestEnvironment);

    return RUN_ALL_TESTS();
}
#endif

//////////////////////////////////////////////////////////////////////
// README in gtest.h
// You should call this before RUN_ALL_TESTS() is called, probably in
// main().  If you use gtest_main, you need to call this before main()
// starts for it to take effect.  For example, you can define a global
// variable like this:
//
//   testing::Environment* const foo_env =
//       testing::AddGlobalTestEnvironment(new FooEnvironment);
//
// However, we strongly recommend you to write your own main() and
// call AddGlobalTestEnvironment() there, as relying on initialization
// of global variables makes the code harder to read and may cause
// problems when you register multiple environments from different
// translation units and the environments have dependencies among them
// (remember that the compiler doesn't guarantee the order in which
// global variables from different translation units are initialized).
