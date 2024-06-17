module;

// #include <print>
#include <string>
// #include <vector>
// #include <cstdint>
// #include <functional>



export module bitcask:error;


namespace bitcask {

export class Error {
public:
    Error(){}
private:
    std::string info;
};

}
