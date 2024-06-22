module;

#include <string>


export module bitcask:error;


namespace bitcask {

export class Error {
public:
    Error(){}
private:
    std::string info;
};

}
