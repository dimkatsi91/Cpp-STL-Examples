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

TEST(FiboTest, findFiboNums) {
	FIBO F(10);
	F.find_fibo();
	vector<int> correct={0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
	for(size_t i=0; i<10; i++) {
			ASSERT_EQ(correct[i], F.get_fibo_nums(i));
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
