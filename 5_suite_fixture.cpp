#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>

#define delay(s) sleep(s)   

using namespace std;

class Database{
private:
    bool b_login=false;
public:
	void connect(){  delay(1); }
	void disconnect(){ delay(2); }
	void login(const string&id, const string& password){b_login=true;}
	void logout(){b_login=false;}

	bool isLogin(){ return b_login;}
};

//#iclude Database.h
#include "gtest/gtest.h"

class DatabaseTest: public ::testing::Test{
protected:
    static Database* database;
    static void SetUpTestCase(){
        printf("SetupTestCase\n");
        database = new Database;
	    database->connect();

    }

    static void TearDownTestCase(){
        printf("TearDownTestCase() \n");
        database->disconnect();
	    delete database;
    }

    virtual void SetUp(){
    }

    virtual void TearDown(){
    }
};

Database* DatabaseTest::database = 0;

// if fixture setup is too slow, it affects on every tests
// ==> slow Test : developes are reluctant to test 
//		-> low productivity
// ==> suitefixture
// purpose: resolve slow test
// problem : each test cases are not isloated
// jUnit4+ (@BforeClass/ @BeforeAll)

TEST_F(DatabaseTest, loginTest)
{
	database->login("test_id", "test_pw");
	ASSERT_TRUE(database->isLogin());
}

TEST_F(DatabaseTest, logoutTest)
{
	database->logout();
	ASSERT_FALSE(database->isLogin());

}

TEST_F(DatabaseTest, foo)
{
    //I dont want to be slow..
}
