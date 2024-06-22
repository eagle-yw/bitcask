
import bitcask;


int main(int argc, char* argv[]){



    auto engine = bitcask::Engine();
    engine.Open("");
    bitcask::Error();

    return 0;
}
