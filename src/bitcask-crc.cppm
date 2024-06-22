module;

#include <string>
#include <cstdint>
#include <vector>


export module bitcask:crc;


import :byte;

namespace bitcask {

export class CRC32 {
public:
    static auto GetInstance()-> const CRC32& {
        auto static instance = CRC32();
        return instance;
    }

    auto GetCRC32(const Byte& data) const -> uint32_t {
        return 0;
    }
private:
    CRC32(){
        this->MakeCrcTable();
    }
    ~CRC32(){}

    auto MakeCrcTable()-> void {
        table_32_.resize(256);
        for(int i = 0; i < 256; i++){
            uint32_t c = i;
            for(int j = 0; j < 8; j++){
                if(c & 1){
                    c = 0xedb88320 ^ (c >> 1);
                } else {
                    c = c >> 1;
                }
            }
            table_32_[i] = c;
        }
    }
    std::vector<uint32_t> table_32_;
    std::string info;
};

}