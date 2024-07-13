#include <iostream>
#include "handled.h"
#include "helpd.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> args;
    std::string output;
    for(int i=1; i<argc; ++i) {
        args.push_back(argv[i]);
    }
    if(args.size()==0) {
        // TODO: 命令行模式
        // ONLY TEST
        std::cout << "not supported yet." << std::endl;
        return 0;
    }
    std::string cmd = args[0];
    if(cmd == "-h" or cmd =="--help") {
        output = get_help();
    } else if (cmd == "-v" or cmd == "--version") {
        output = get_version();
    }
    else {
        std::cerr << unknown_cmd() << std::endl;
        return 1;
        
    }
    std::cout << output << std::endl;
}