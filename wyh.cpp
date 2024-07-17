/*
def check_single_or_multiple_ways(F):
    count = 0
    for a in range(F // 7 + 1):
        for b in range((F - 7 * a) // 9 + 1):
            c = (F - 7 * a - 9 * b) / 11
            if c.is_integer() and c >= 0:
                count += 1
                if count > 1:
                    return "multiple ways"
    return "single way" if count == 1 else "no combinations"

F_values = input().split()

for F in F_values:
    result = check_single_or_multiple_ways(F)
    print(f"F = {F}: {result}")
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define FOR(name, max) for(int _##name=0; _##name<max; _##name ++)

#include <sstream>

#define DOUBLE_TO_STRING(name,value)\
double _j##name = value;\
std::stringstream ss##name;\
ss##name<<_j##name;\
std::string name = ss##name.str();\

int double_to_int(int a, int b) {
    double c = a/b;
    int answer=0;
    for(int p=0; p<c; p++) {
        answer++;
    }
    return answer;
}

int main(int argc, char* argv[]) {
    std::vector<int>  args;
    for(int i=1; i<argc; i++) {
        args.push_back(std::stoi(argv[i]));
    }

}

std::string csmw(int *p) {
    int count = 0;
    int q = *p;
    FOR(a, double_to_int(q, 7)+1) {
        FOR(b, double_to_int(q-7*_a, 9)+1) {
            double c = (*p - 7*_a - 9*_b) / 11;
            DOUBLE_TO_STRING(jc, c);
            if(jc[jc.size()-1]=='0' and jc[jc.size()-2]=='.') {
                count++;
                if(count>1) {
                    return "multiple ways";
                }
            }
        }
    }
    if(count==1) {
        return "single way";
    } else {
        return "no combinations";
    }
}