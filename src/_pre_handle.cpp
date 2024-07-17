#include "../include/handle.h"
#include "../include/imath.h"

std::vector<std::string> _compile_evaluate(std::string newline) {
    std::string var_name = "";
    std::string opt_str = "";
    std::vector<std::string> answer;
    bool is_only_num = true;
    bool met=false;
    for (int index = 0; index < newline.size() - 1; index++) {
        char i = newline[i];
        if(i=='=') {
            met=true;
        }
        if (!met) {
            var_name.push_back(i);
        } else {
            opt_str.push_back(i);
            // 判断是否数字
            // std::cout << i << " ";
            if (!isin(i, NUMBERS) && !isin(i, CALCULATORS)) {
                is_only_num = false;
            }
        }
    }
    char legality = islegal(var_name);
    if (legality != ' ') {
        std::string error_mes = "Ilegal var name with '";
        error_mes.push_back(legality);
        throw SyntaxError(error_mes + "'.");
    }
    // TEST
    // std::cout << is_only_num << std::endl;
    // 优化纯静态数字
    if (is_only_num) {
        double static_answer = calculate(opt_str);
        std::stringstream answer_string_ss;
        std::string answer_string;
        answer_string_ss << std::setprecision(_FLOAT_DIGITS) << static_answer;
        answer_string = answer_string_ss.str();
        answer = {"set", var_name, answer_string};
    } else {
        answer = {"set", var_name, opt_str};
    }
    return answer;
}


std::vector<std::string> _compile_execute(std::string newline) {
    // functioname(arg1, arg2, test1(xxx), name=arg3, name2=test2(xxx, t=yyy))
    std::string tmp="";
    std::string _executor="";
    std::vector<std::string> args;
    short left=0; short right=0;
    for(int index=0; index<newline.size()-1; index++) {
        char cur = newline[index];
        if(_executor=="") {
            if(isin(cur, NONE)) {
                continue;
            } else {
                if(cur=='(') {
                    if(tmp!="") {
                        _executor = tmp;
                        args.push_back(_executor);
                        tmp = "";
                    } else {
                        throw SyntaxError("No function name found but '(' found.");
                    }
                    left++;
                } else {
                    tmp.push_back(cur);
                }
            }
        } else {
            if(cur==',') {
                if(left==1) {
                    if(tmp!="") {
                        args.push_back(tmp);
                        tmp="";
                    }
                } else {
                    tmp.push_back(cur);
                }
                
            } else if (cur==')') {
                right++;
                if(left==right) {
                    continue;
                } else {
                    tmp.push_back(cur);
                }
            } else if (cur=='(') {
                left++;
                tmp.push_back(cur);
            } else{
                tmp.push_back(cur);
            }
        }
    }
    if(tmp!="") {
        args.push_back(tmp);
    }
    return args;
}