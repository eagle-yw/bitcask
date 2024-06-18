#include <memory>
module;

#include <string>
#include <vector>
#include <cstdint>
#include <optional>


export module bitcask:keydir;

namespace bitcask {


export class Byte {
public:
    auto FromString(const std::string& key) {
        data.clear();
        data.resize(key.size());
        std::copy(key.begin(), key.end(), data.begin());
    };
    
private:
    std::vector<uint8_t> data;
};

enum class LogRecordType {
    kNormal,
    kDeleted
};

export class LogRecord {
public:
private:
    Byte key_;
    Byte value_;
    LogRecordType type_;
};


export class LogRecordPos {
public:
private:
    uint32_t fid_;
    uint64_t offset_;
};


// KeyDir's container interface
export class KeyDirContainer {
public:    
    virtual auto Get(const Byte& key) -> std::optional<LogRecordPos>;
    virtual auto Put(const Byte& key, const LogRecordPos& pos) -> bool;
    virtual auto Delete(const Byte& key) -> bool;
};



export class KeyDir {
public:
    KeyDir(){}
private:
    // container interface
    std::unique_ptr<KeyDirContainer> container;
};

}