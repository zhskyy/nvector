#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
	std::cout << "hello, Nykytich! Let try to run all tests..." << std::endl;	
	::testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}
