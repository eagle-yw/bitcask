module;

#include <print>
#include <string>
#include <vector>
#include <cstdint>
#include <functional>


export module bitcask:engine;


import :keydir;
import :error;



namespace bitcask {



export void bitcask() {
    std::println("bitcask module!");
}


export class Options {

};

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
    auto Get(const Byte& key){};
    auto Put(const Byte& key, const Byte& value){};
    auto Delete(const Byte& key){};
    auto ListKeys(std::function<void(Byte&)> func) -> void{};
    auto Fold(std::function<void(Byte&, Byte&)> func){};
    auto Merge(std::string director){};
    auto Sync()-> void{};
    auto Close(){};

private:
    Options opts_;    
};

}



