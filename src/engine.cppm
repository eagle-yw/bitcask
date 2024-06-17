module;

#include <print>
#include <string>
#include <vector>
#include <cstdint>
#include <functional>  


export module bitcask:engine;

import :error;

namespace bitcask {



export void bitcask() {
    std::println("bitcask module!");
}


export class Options {

};

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


export using Key = Byte;
export using Value = Byte;


export class Engine {
public:
    Engine() {

    }

    Engine(Options& opts) {
        opts_ = opts;
    }

    auto Open(std::string director){
        return Error();
    };
    auto Open(std::string director, Options opts){};
    auto Get(const Key& key){};
    auto Put(const Key& key, const Value& value){};
    auto Delete(const Key& key){};
    auto ListKeys(std::function<void(Key&)> func) -> void{};
    auto Fold(std::function<void(Key&, Value&)> func){};
    auto Merge(std::string director){};
    auto Sync()-> void{};
    auto Close(){};

private:
    Options opts_;    
};

}



