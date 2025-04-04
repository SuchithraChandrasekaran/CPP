#include <gtest/gtest.h>

// Function to be tested
int add(int a, int b) 
{
    return a + b;
}

// Test cases
TEST(Test, PositiveNumbers) 
{
    EXPECT_EQ(add(2, 3), 5);  // Normal case
}

TEST(Test, NegativeNumbers) 
{
    EXPECT_EQ(add(-2, -3), -5);  // Both negative
    EXPECT_EQ(add(-2, 3), 1);   // Mixed signs
}

TEST(Test, EdgeCases) 
{
    EXPECT_EQ(add(0, 0), 0);  // Zero case
    EXPECT_EQ(add(2147483647, 0), 2147483647); // Max int + 0
    EXPECT_EQ(add(-2147483648, 0), -2147483648); // Min int + 0
}

// Main function
int main() 
{
    return RUN_ALL_TESTS();
}
