#include <gtest/gtest.h>


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(SomeTest, DoesThis) {
    ASSERT_EQ(1, 1);
}