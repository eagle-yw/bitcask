module;

#include <string>
#include <vector>
#include <cstdint>

export module bitcask:byte;


namespace bitcask {

export class Byte {
public:
    static auto FromString(const std::string& key) -> Byte {
        auto data = Byte();
        data.resize(key.size());
        std::copy(key.begin(), key.end(), data.begin());
        return data;
    };

    using iterator = std::vector<uint8_t>::iterator;
    
    auto begin() -> iterator {
        return data_.begin();
    }
    auto end() -> iterator {
        return data_.end();
    }

    using const_iterator = std::vector<uint8_t>::const_iterator;
    auto begin() const -> const_iterator {
        return data_.begin();
    }
    auto end() const -> const_iterator {
        return data_.end();
    }

    auto operator[](const size_t idx) -> uint8_t&{ 
        return this->data_[idx];
    }

    auto operator[](const size_t idx) const -> const uint8_t&{ 
        return this->data_[idx];
    }

    // for copy
    Byte(const Byte& b){
        data_ = std::move(b.data_);
    }
    auto operator=(const Byte& b) -> Byte{
        return Byte(b);  
    }
    
    // for move
    Byte(Byte&& b) {
        data_ = std::move(b.data_);
    }

    auto operator=(Byte&& b) -> Byte&{
        data_ = std::move(b.data_);
        return *this;
    }
    // for compare
    auto operator==(const Byte& b) const -> bool {
        return this->data_ == b.data_;
    }

    auto operator!=(const Byte& b) const -> bool {
        return this->data_ != b.data_;
    }

    auto size() -> size_t {
        return this->data_.size();
    }
    
private:  
    Byte(): data_() {};

    auto resize(size_t n) -> Byte& {
        data_.resize(n);
        return *this;
    }

    std::vector<uint8_t> data_;
};



}