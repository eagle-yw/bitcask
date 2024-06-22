module;


#include <string>
#include <vector>
#include <cstdint>
#include <optional>
#include <memory>


export module bitcask:keydir;

import :byte;

namespace bitcask {


export enum class LogRecordType {
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
class KeyContainer {
public:    
    virtual auto Get(const Byte& key) -> std::optional<LogRecordPos>;
    virtual auto Put(const Byte& key, const LogRecordPos& pos) -> bool;
    virtual auto Delete(const Byte& key) -> bool;
};



export class KeyDir {
public:
    KeyDir(){}
private:
    // container interface;
    std::unique_ptr<KeyContainer> container;
};

}