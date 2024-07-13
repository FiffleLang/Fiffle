#include "helpd.h"

//! 下面的include发行时删除
// #include "_release.h"

const std::string VERSION = "0.1beta";

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


std::string unknown_cmd() {
    return R"(Unknown command.)";
}

#ifdef _RELEASE_VERSION
    std::string _released_get_version() {
        std::string compiler = _RELEASE_COMPILER;
        std::string compiler_version = _RELEASE_COMPILER_VERSION;
        std::string platform = _RELEASE_PLATFORM;
        return "(Released, "+compiler+" "+compiler_version+" on "+platform+")";
    }

#else
    std::string _unreleased_get_version() {
        // 格式：fiffle 1.0.0 (Released, GCC 8.2.0(32-bit) on linux 32-bit)
        std::string version_str; // GCC 8.2.0
        #ifdef __clang__
            version_str+="Clang ";
            std::string t = std::to_string(__clang_major__) + "." + std::to_string(__clang_minor__) + "." + std::to_string( __clang_patchlevel__);
            version_str+=t;
        #elif defined(__GNUC__)
            version_str+="GCC ";
            std::string t = std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "." + std::to_string(__GNUC_PATCHLEVEL__);
            version_str += t;
        #elif defined(_MSC_VER)
            version_str += "MSVC ";
            version_str += std::to_string(_MSC_VER);
        #else
            version_str += "Unknown Compiler";
        #endif
        
        #if defined(__LP64__) || defined(_WIN64)
            version_str += "(64-bit)";
        #else
            version_str += "(32-bit)";
        #endif
        
        version_str += " on ";

        #ifdef _WIN32
            #ifdef _WIN64
                version_str += "Windows 64bit";
            #else
                version_str += "Windows 32bit";
            #endif
        #else
            #ifdef __linux__
                version_str += "linux";
            #else
                version_str += "others";
            #endif
        #endif

        return "(Unreleased, "+version_str+")";
    }

#endif


std::string get_version() {
    // 需要判断是released的二进制版本还是自行构建的版本
    // 这里使用源码宏的方式定义, 即官方release时会定义宏 _RELEASE_VERSION 和 _RELEASE_PLATFORM 等
    // 如果未定义宏就认为是自行构建的版本
    #ifdef _RELEASE_VERSION
        return "fiffle "+VERSION+" "+_released_get_version();
    #else
        return "fiffle "+VERSION+" "+_unreleased_get_version();
    #endif
}