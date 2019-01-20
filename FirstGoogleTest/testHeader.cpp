/* This is the function that tests the functions from the header file */
#include "header.h"

#include <gtest/gtest.h>


TEST(FactTest, smallNumber) {
	ASSERT_EQ(120, fact(5));
	ASSERT_EQ(24, fact(4));
}

TEST(FactTest, NegativeOrZero) {
	ASSERT_EQ(0, fact(-1));
	ASSERT_EQ(0, fact(0));
}

TEST(FactTest, BigNumber) {
	ASSERT_EQ(3628800, fact(10));
	ASSERT_EQ(39916800, fact(11));
	ASSERT_EQ(2432902008176640000, fact(20));
}


TEST(FiboTest, find5FiboNums) {
	FIBO F(5);
	F.find_fibo();
	ASSERT_EQ(0, F.get_fibo_nums(0));
	ASSERT_EQ(1, F.get_fibo_nums(1));
	ASSERT_EQ(1, F.get_fibo_nums(2));
	ASSERT_EQ(2, F.get_fibo_nums(3));
	ASSERT_EQ(3, F.get_fibo_nums(4));
}



int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
