#include "helpd.h"

std::string _win_get_help() {
    return R"(This is Fiffle (Language).
usage: fiffle.exe [option] [file] [-i output_file]
Options:
    -c file : compile the file and exit, don't execute it.
    -t file : try to compile the file and exit, print if there's syntax error and don't output file.fic.
    -g file : copy files-compiled imported in file.
    -v --version
            : output the current fiffle version and exit.
    -h --help
            : output this help message and exit.
    
If there is no [option], fiffle will try to compile and run [file].
If there is no [option] and no [file], fiffle will run in command-line mode.

Copyleft Fiffle.
    )";
}


std::string _unix_get_help() {
    return R"(This is Fiffle (Language).
usage: fiffle [option] [file] [-i output_file]
Options:
    -c file : compile the file and exit, don't execute it.
    -t file : try to compile the file and exit, print if there's syntax error and don't output file.fic.
    -g file : copy files-compiled imported in file.
    -v --version
            : output the current fiffle version and exit.
    -h --help
            : output this help message and exit.
    
If there is no [option], fiffle will try to compile and run [file].
If there is no [option] and no [file], fiffle will run in command-line mode.

Copyleft Fiffle.
    )";
}


std::string get_help() {
    #ifdef _WIN32
        return _win_get_help();
    #else
        return _unix_get_help();
    #endif
}