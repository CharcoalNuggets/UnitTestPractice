/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("eer");
	ASSERT_EQ(2, actual);
	actual = my_password.count_leading_characters("Eeer");
	ASSERT_EQ(1, actual);
	actual = my_password.count_leading_characters("eEEr");
	ASSERT_EQ(1, actual);
	actual = my_password.count_leading_characters("EEEEr");
	ASSERT_EQ(4, actual);
	actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, aa_test)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, AAA_test)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AAA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, aAaA_test)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aAaA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, empty_test)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
