// Memory => check if there is mem leack when spacific function called
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef ALLOC_TEST
#define DECLARE_ALLOC_TEST()            \
    static int allocCount;              \
	void* operator new(size_t size){    \
        ++allocCount;                   \
		printf("object created!\n");    \
		return malloc(size);            \
	}                                   \
	void operator delete(void* p , size_t){ \
        --allocCount;                       \
		printf("object destructed!\n");     \
		free(p);                            \
	}

#define IMPLEMENT_ALLOC_TEST(classname)     \
int classname::allocCount=0             
#else 
#define DECLARE_ALLOC_TEST()
#define IMPLEMENT_ALLOC_TEST(classname)
#endif

class Image{
public:
    DECLARE_ALLOC_TEST()
};

IMPLEMENT_ALLOC_TEST(Image);

///////////////////////////////////////////////////////////
#include "gtest/gtest.h"

class ImageTest: public ::testing::Test {
protected:
    int count;

    void SetUp(){
        count = Image::allocCount;
    }

    void TearDown() {
        int diff = Image::allocCount - count;
        printf("diff : %d\n", diff);
        EXPECT_EQ(0, diff) << "Leak = " <<diff <<"object(s)";
    }
};

void foo() {
    Image* image = new Image;
    Image* image2 = new Image;

    //delete image;
    //delete image2;
}

TEST_F(ImageTest, memoryTest)
{
    foo();
}
