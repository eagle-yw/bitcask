#include <gtest/gtest.h>

import bitcask;

TEST(UnitTest, TestCRC32) {
    auto str = std::string("test crc32");    
    auto data = bitcask::Byte::FromString(str);

    auto& cal = bitcask::CRC32::GetInstance();
    auto crc32 = cal.GetCRC32(data);
    ASSERT_EQ(crc32, uint32_t(0x5E01CA41));
}