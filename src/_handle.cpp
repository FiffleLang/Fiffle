#include "../include/basicd.h"

bool is_empty(std::string str) {
    for(char s:str) {
        if(s!=' ' and s!='\n' and s!='\r' and s!='\t') {
            return false;
        }
    }
    return true;
}

/*
compile a line of code
*/
auto _compile() {

}

/*
    Handle with a complete code-file.
*/  
std::vector<std::string> handle_all(short type_of_operation, std::string filename) {
    // If it is a file?
    if(type_of_operation==1) {
        // 依次读入每一行
    }
}