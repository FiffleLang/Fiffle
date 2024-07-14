#include "basicd.h"

bool is_empty(std::string str) {
    for(char s:str) {
        if(s!=' ' and s!='\n' and s!='\r' and s!='\t') {
            return false;
        }
    }
    return true;
}

auto compile() {
    
}