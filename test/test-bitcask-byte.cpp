#include <gtest/gtest.h>
#include <iostream>

import bitcask;

TEST(UnitTest, ByteForRange) {
    auto str = std::string("test byte");    
    auto data1 = bitcask::Byte::FromString(str);

    int i = 0;
    for(auto it: data1){
        ASSERT_EQ(static_cast<uint8_t>(str[i]), it);
        i++;
    }

    for(i = 0; i < static_cast<int>(str.size()); i++){
        ASSERT_EQ(static_cast<uint8_t>(str[i]), data1[i]);
    }  

    i = 0;
    const auto data2 = bitcask::Byte::FromString(str);
    for(auto it: data2){
        ASSERT_EQ(static_cast<uint8_t>(str[i]), it);
        i++;
    }  
}

TEST(UnitTest, ByteCopy) {
    auto str = std::string("test byte");     
    auto data = bitcask::Byte::FromString(str);
    //copy
    auto data1 = bitcask::Byte(data);
    auto data2 = data;

    int i = 0;
    for(auto it: data1){
        ASSERT_EQ(str[i], it);
        i++;
    }

    i = 0;
    for(auto it: data2){
        ASSERT_EQ(str[i], it);
        i++;
    }    
}

TEST(UnitTest, ByteMove) {
    auto str = std::string("test byte");   
    auto data = bitcask::Byte::FromString(str);
    auto data1 = std::move(data);


    int i = 0;
    for(auto it: data1){
        ASSERT_EQ(str[i], it);
        i++;
    }
    ASSERT_EQ(data.size(), 0); 
 
}

TEST(UnitTest, ByteCompare) {
    auto str1 = std::string("test byte1");
    auto str2 = std::string("test byte2");     
    //copy
    auto data1 = bitcask::Byte::FromString(str1);
    auto data2 = bitcask::Byte::FromString(str2);

    ASSERT_FALSE((data1 == data2));
    ASSERT_TRUE((data1 != data2));
}