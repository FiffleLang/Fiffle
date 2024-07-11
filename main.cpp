#include <iostream>
#include "handled.h"
#include "helpd.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> args;
    std::string output;
    for(int i=1; i<argc; ++i) {
        args.push_back(argv[i]);
    }
    if(args[0] == "-h" or args[0]=="--help") {
        output = get_help();
    }
    std::cout << output << std::endl;
}