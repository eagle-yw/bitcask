#include <gtest/gtest.h>

import bitcask;

TEST(UnitTest, ByteForRange) {
    auto str = std::string("test byte");    
    auto data = bitcask::Byte::FromString(str);

    int i = 0;
    for(auto it: data){
        ASSERT_EQ(str[i], it);
        i++;
    }
}