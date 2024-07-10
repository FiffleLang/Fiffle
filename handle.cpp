#include "handle.h"
#include "imath.h"

class SyntaxError {
    public:
        SyntaxError(const std::string& error_msg) : 
        _error_msg(error_msg) {}
    virtual std::string what() const {
        return "SyntaxError: " + _error_msg ;
    }
    protected:
        std::string _error_msg;
};

/*
Split string into vector<string> using delimiter.

Params:
    string(string): the string need to be splited
    delimiter(string): the seprator
*/
std::vector<std::string> split(std::string string, std::string delimeter, int start, int end) {
    if (delimeter.length() == 1) {
        std::vector<std::string> result;
        std::string s;
        if(start >= string.length()) {
            return {};
        }
        if(end <= -1 - string.length()) {
            return {};
        }
        for (int j = 0; j<=string.length()+end; j++) {
            char i = string[j];
            if (i!=delimeter[0]) {
                s.push_back(i);
                continue;
            } else {
                if(s!="") {
                    result.push_back(s);
                }
                s="";
            }
            
        }
        if (s.length() > 0) { result.push_back(s); }
        return result;
    } else if (delimeter.length() == 0) {
        return split(string, " ");
    } else {
        std::vector<std::string> tokens;
        size_t pos = 0;

        while ((pos = string.find(delimeter)) != std::string::npos) {
            tokens.push_back(string.substr(0, pos));
            string = string.substr(pos + 1);
        }

        tokens.push_back(string);
        return tokens;
    }
}


/*
Split string into vector<string> using delimiter and keep it.
*/
std::vector<std::string> split_and_keep(std::string string, char delimeter, int start, int end) {
    std::string delt = "";
    delt.push_back(delimeter);
    std::vector<std::string> result;
    std::string tem = "";
    if(start >= string.length()) {
        return {};
    }
    if(end <= -1 - string.length()) {
        return {};
    }
    for (int i = 0; i<=string.length()+end; i++) {
        char s = string[i];
        if(s==delimeter) {
            if(tem!="") {
                result.push_back(tem);
            }
            result.push_back(delt);
            tem="";
        } else {
            tem.push_back(s);
        }
    }
    if(tem!="") {
        result.push_back(tem);
    }
    return result;
}

// TEST CODE
// Run this without comments 
/*
int main() {
    std::string input = "This is a test string with multiple words and some special characters: @#$%^&*()_+=-{}[]|\\:;\"'<>,.?/`~";
    std::vector<std::string> words = split(input);
    for (std::string str : words) {
        std::cout << str << ", ";
    }
    std::cout << std::endl;
    return 0;
}
*/


/*
Return if the element in the list.

Params:
    element(int, string, char)
    list(vector<int>, vector<string>, vector<char>, string)
*/
bool isin(int element, std::vector<int> list) {
    for(int l:list) {
        if(l==element) {
            return true;
        }
    };
    return false;
}
bool isin(std::string element, std::vector<std::string> list) {
    for(std::string l:list) {
        if(l==element) {
            return true;
        }
    };
    return false;
}
bool isin(char element, std::vector<char> list) {
    for(char l:list) {
        if(l==element) {
            return true;
        }
    };
    return false;
}
bool isin(char element, std::string list) {
    for(char l:list) {
        if(l==element) {
            return true;
        }
    };
    return false;
}


/*
Check if a variable name is legal.
*/
char islegal(std::string name) {
    for(char i:name) {
        if(isin(i, ILEGAL_CHARS)) {
            return i;
        }
    }
    return ' ';
}



void print(std::string message) {
    std::cout << message << std::endl;
}
void print(std::string message, bool iferror) {
    if(iferror) {
        std::cerr << message << std::endl;
    }
}




// Calculate static
std::map<char, int> out = { {'#', 0}, {'(', 8}, {'^', 6}, {'*', 4}, {'/', 4}, {'%', 4},{'+', 2}, {'-', 2},{')', 1} };
std::map<char, int> inside = { {'#', 0}, {'(', 1}, {'^', 7}, {'*', 5}, {'/', 5}, {'%', 5}, {'+', 3},{'-', 3},{')', 8} };



// 中缀表达式->后缀表达式
std::vector<Node> midToBack(std::string mid) {
	std::vector<Node> back;
	if (mid.size() == 0) return back;
	// 去空格
	std::string s;
	for (char c : mid) { 
		if (c != ' ')
			s.push_back(c);
	}

	// 处理负数
	if (s[0] == '-') {
		s.insert(0, "0");
	}
    if (s[0] == '+') {
		s.insert(0, "0");
	}
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == '(' && s[i + 1] == '-')
			s.insert(i + 1, "0");
	}
	mid = s;

	std::stack<char> op;
	op.push('#');
	bool flag = false; //记录上次存入的是否为数字
	for (int i = 0; i < mid.size(); i++) {
		if (mid[i] >= '0' && mid[i] <= '9') { // 操作数不进栈
			if (flag == false) {
				flag = true;
				int tmp = mid[i] - '0';
				back.push_back(Node(tmp, false));
			}
			else {
				back.back().num *= 10;
				back.back().num += mid[i] - '0';
			}
		}
		else if (out[mid[i]] > inside[op.top()]) { // 操作符比栈顶操作符优先级高，则进栈
			flag = false;
			op.push(mid[i]);
		}
		else if (out[mid[i]] < inside[op.top()]) { // 操作符比栈顶操作符优先级低，则栈顶操作符出栈
			flag = false;
			back.push_back(Node(op.top(), true));
			op.pop();
			i--;
		}
		else { // 操作符与栈顶操作符优先级相同，则匹配括号
			flag = false;
			op.pop();
		}
	}
	while (op.top() != '#') {
		back.push_back(Node(op.top(), true));
		op.pop();
	}
	return back;
}

// 求解后缀表达式
double getValue(std::vector<Node> back) {
	if (back.size() == 0) return 0;
	std::stack<double> nums;
	for (auto e : back) {
		if (!e.isop) {
			nums.push(e.num);
		}
		else {
			double b = nums.top();
			nums.pop();
			double a = nums.top();
			nums.pop();
			double res;
			switch (e.op)
			{
			case '+':
				res = a + b; break;
			case '-':
				res = a - b; break;
			case '*':
				res = a * b; break;
			case '/':
				res = a / b; break;
			case '^':
				res = pow(a, b); break;
			case '%':
				res = int(a) % int(b); break;
			default:
				break;
			}
			nums.push(res);
		}
	}
	return nums.top();
}


double calculate(std::string expression) {
	auto back = midToBack(expression);
	double res = getValue(back);
    return res;
}





/*
Handle with a line of ITEA code into tokens.
将代码进行预编译，输出tokens。运行时无需再次编译。tokens的格式：
编译步骤：拆分段落 -> 拆分语句 -> 编译每个语句 -> 编译代码块 -> 链接代码块
运行步骤: 遍历代码块 -> 遍历语句 -> 执行 -> 返回结果 -> goto循环
Params:
    temp(vector<string>): tokens handles.
*/
std::vector<std::string> handle_one_line(std::string newline) {
    std::vector<std::string> tokens_of_the_line = split(newline, " ");
    // the answer
    std::vector<std::string> answer;
    if (tokens_of_the_line.size()==0) {
        return {};
    }
    std::string operation = tokens_of_the_line[0];
    if(isin(operation, KEY_WORDS)) {
        // this means that this line of code is used to define a function or a class // 此行为定义函数或类
        // either to import something // 或者import
        // TODO
        return {};
    } else {
        // this means that this line of code is used to evaluate a variable // 此行为赋值操作
        // or execute a function // 或者执行一个函数
        std::string end_of_line;
        int length_of_line = newline.length();
        end_of_line.push_back(newline[length_of_line-1]);
        if (end_of_line==SP) {
            // Author: Alex
            // Started at 24 07 09
            // 这是一行将运算结果赋值的
            // 先验证是否有=号
            if(isin('=', newline)) {
                std::string var_name = "";
                std::string opt_str = "";
                bool is_only_num = true;
                // 处理变量赋值
                // 先分为变量名和变量值
                bool met=false;
                for(int x = 0 ; x < newline.size()-1 ; x++) {
                    char i = newline[x];
                    if(i=='=') {
                        if(met){
                            throw SyntaxError("Too many equators '=' found.");
                            continue;
                        }
                        met=true;
                        continue;
                    }
                    if(!met) {
                        var_name.push_back(i);
                    } else {
                        opt_str.push_back(i);
                        // 判断是否数字
                        // std::cout << i << " ";
                        if(!isin(i, NUMBERS) && !isin(i, CALCULATORS)) {
                            is_only_num = false;
                        }
                    }
                }
                // 检查变量名是否合法
                char legality = islegal(var_name);
                if(legality!=' ') {
                    std::string error_mes = "Ilegal var name with '";
                    error_mes.push_back(legality);
                    throw SyntaxError(error_mes+"'.");
                }
                // TEST
                // std::cout << is_only_num << std::endl;
                // 优化纯静态数字
                if(is_only_num) {
                    double static_answer = calculate(opt_str);
                    std::stringstream answer_string_ss;
                    std::string answer_string;
                    answer_string_ss << std::setprecision(_FLOAT_DIGITS) << static_answer;
                    answer_string = answer_string_ss.str();
                    answer = {"set", var_name, answer_string};
                } else {
                    answer = {"set", var_name, opt_str};
                }

            } else {
                throw SyntaxError("Excepting equator '=' but not found.");
            }
        } //TODO else if () {

        else {
            throw SyntaxError("Excepting seperator ';' but not found.");
        }
        return answer;
    }
}

int main() {
    auto a = std::chrono::steady_clock::now();
    try {
        std::string code = "a=4+5*60;";
        std::vector<std::string> tokens = handle_one_line(code);
        for(std::string token : tokens) {
            std::cout<< token<< ", " ;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    auto b = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::micro>(b-a).count();
}