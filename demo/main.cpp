#include <print>


import bitcask;


int main(int argc, char* argv[]){

    std::println("Hello, from bitcask!");

    auto engine = bitcask::Engine();
    engine.Open("");
    bitcask::Error();

    return 0;
}
