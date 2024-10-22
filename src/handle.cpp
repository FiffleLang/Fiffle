#include "../include/handle.h"
#include "../include/imath.h"
#include "../include/_pre_handle.h"

#define get_fiffle_op(s) _get_fiffle_op.at(s)
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
        ssize_t pos = 0;

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
template <typename T,typename K>
    element(T)
    list(K) // Iterative types
*/
template <typename T, typename K>
bool isin(T element, K list)
{
    for (auto l : list)
    {
        if (l == element)
        {
            return true;
        }
    }
    return false;
}

/*
Check if a variable name is legal.
*/
char islegal(std::string name)
{
    for (char i : name)
    {
        if (isin(i, ILEGAL_CHARS))
        {
            return i;
        }
    }
    return EMPTY;
}

void print(std::string message)
{
    std::cout << message << std::endl;
}
void print(std::string message, bool iferror)
{
    if (iferror)
    {
        std::cerr << message << std::endl;
    }
}

// Calculate static
std::map<char, int> out = {{'#', 0}, {'(', 8}, {'^', 6}, {'*', 4}, {'/', 4}, {'%', 4}, {'+', 2}, {'-', 2}, {')', 1}};
std::map<char, int> inside = {{'#', 0}, {'(', 1}, {'^', 7}, {'*', 5}, {'/', 5}, {'%', 5}, {'+', 3}, {'-', 3}, {')', 8}};

// 中缀表达式->后缀表达式
std::vector<Node> midToBack(std::string mid)
{
	std::vector<Node> back;
    if (mid.size() == 0)
        return back;
	// 去空格
	std::string s;
    for (char c : mid)
    {
		if (c != ' ')
			s.push_back(c);
	}

	// 处理负数
    if (s[0] == '-')
    {
		s.insert(0, "0");
	}
    if (s[0] == '+')
    {
		s.insert(0, "0");
	}
    for (int i = 0; i < s.size() - 1; i++)
    {
		if (s[i] == '(' && s[i + 1] == '-')
			s.insert(i + 1, "0");
	}
	mid = s;

	std::stack<char> op;
	op.push('#');
    bool flag = false; // 记录上次存入的是否为数字
    for (int i = 0; i < mid.size(); i++)
    {
        if (mid[i] >= '0' && mid[i] <= '9')
        { // 操作数不进栈
            if (flag == false)
            {
				flag = true;
				int tmp = mid[i] - '0';
                back.push_back(Node(tmp));
			}
            else
            {
				back.back().num *= 10;
				back.back().num += mid[i] - '0';
			}
		}
        else if (out[mid[i]] > inside[op.top()])
        { // 操作符比栈顶操作符优先级高，则进栈
			flag = false;
			op.push(mid[i]);
		}
        else if (out[mid[i]] < inside[op.top()])
        { // 操作符比栈顶操作符优先级低，则栈顶操作符出栈
			flag = false;
            back.push_back(Node(op.top()));
			op.pop();
			i--;
		}
        else
        { // 操作符与栈顶操作符优先级相同，则匹配括号
			flag = false;
			op.pop();
		}
	}
    while (op.top() != '#')
    {
        back.push_back(Node(op.top()));
		op.pop();
	}
	return back;
}

// 求解后缀表达式
double getValue(std::vector<Node> back)
{
    if (back.size() == 0)
        return 0;
	std::stack<double> nums;
    for (auto e : back)
    {
        if (!e.isop)
        {
			nums.push(e.num);
		}
        else
        {
			double b = nums.top();
			nums.pop();
			double a = nums.top();
			nums.pop();
			double res;
			switch (e.op)
			{
			case '+':
                res = a + b;
                break;
			case '-':
                res = a - b;
                break;
			case '*':
                res = a * b;
                break;
			case '/':
                res = a / b;
                break;
			case '^':
                res = pow(a, b);
                break;
			case '%':
                res = int(a) % int(b);
                break;
			default:
				break;
			}
			nums.push(res);
		}
	}
	return nums.top();
}

double calculate(std::string expression)
{
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

该函数把代码处理成平台码，然后由不同平台不同的execute函数来运行平台码
特殊字符：
    *xxx 表示函数引用
    &xxx 表示变量引用
    @xxx 表示类对象属性引用
    ?xxx 表示判断bool引用
平台码关键字：(带?的是bool)
    set 设置变量的值，格式为                        set <name> <value>
    run 运行函数，格式为                            run <function> <args>
    def 定义外部函数，格式为                        def <function> <args> <?args> <?kwargs> <args_list>
    ret 返回变量，格式为                            ret <name>
    end 退出函数(类内外都是end)定义，格式为          end <function>
    cls 定义类，格式为                              cls <class> <basic_name>
    init 类初始化函数，必须在类中定义，格式为        init <args>
    cset 设置self属性，必须在类中定义，格式为        cset <name> <value>
    cdef 类函数，必须在类中定义，格式为              cdef <function> <args> <?args> <?kwargs> <args_list> <?self>
    cend 结束类定义，格式为                         cend <name>
    loop 循环跳转点，格式为                         loop <name>
    exit 退出循环段，格式为                         exit <name>
    jmp 跳到循环转跳点，格式为                      jmp <name>
    del 删除变量                                    del <name>
    if 条件判断，格式为                             if <condition>
    else 同上(需要展开elif)
    endif 结束条件分支
    print 打印内容                                 print <value>

以下是预处理的结果：
1、
    变量赋值操作，后面是静态的，比如 a=4+4;
    则处理成 set a 8
    TODO：例如 (test(1,2)+3)*4+5-3 这种，可以优化为 4*(test(1,2))+14
    如果是字符串，比如 b = "34" 则处理成 set b "34"
2、
    变量赋值操作，后面是某个函数的返回值，比如 a=demo(1, b=3, c=e, d=test(x=3));
    则处理成：
        set v7705424521944394882 *test [[], {"x":3}]    // 7705424521944394882是“test(x=3)”的哈希绝对值
        set a *demo [[1, ], {"b":3, "c":&e, "d":&v7705424521944394882}]
            / *后面跟的是函数名，比如 *run [...] 是用[]里的参数运行run函数，要提前解包，即json里没有动态结果
            / &后面跟的是变量名，比如 &e 就是e的值

3、运行函数
    比如  demo(1, b=3, c=e, d=test(x=3))
    则处理成：
        set v7705424521944394882 *test [[], {"x":3}]    // 7705424521944394882是“test(x=3)”的哈希绝对值
        run *demo [[1, ], {"b":3, "c":&e, "d":&v7705424521944394882}]

4、定义函数（类外的独立函数）
    比如 func add(a, b) {...}

    func add(a, b=3, *args, **kwargs) {...}
        处理成：
            def add [["a", ], {"b":3, }] 1 1 ["args", "kwargs"]
                # 第一个true表示开启元组全接收，第二个true表示开启字典全接收
                set ...
                run ...
                ret &answer # 如果没有设定返回的内容，即func中没有return语句，加一个 set v5112316013165685643 
            end add

5、定义类和类函数
    比如
    ```
    class MyClass by BasicClass {    # by 关键字用于继承，可以不用（默认继承BasicClass）
        func _init(self, name, num=3) {
            self.name = name;
            self.num = num+1;
        }

        func tostring(self) {
            return self.name;
        }
    } 
    ```
    转化为
    cls MyClass BasicClass
        init [["name", ], {"num":3}] 0 0 []     # self是默认参数
            cset name &name
            cset num &num+1
        end init

        cdef tostring [[], {}] 0 0 [] 1
            ret @name
        end tostring

6、条件分支
    1、判断变量
        比如 
        if (not a) {
            if (b) {
                dosome1();
            } elif (c) {
                dosome2();
            }
        } else {
            dosome3();
        }
        转化为
        if not &a
            if &b
                run *dosome1 [[], {}]
            else
                if &c
                    run *dosome2 [[], {}]
                endif
            endif
        else
            run *dosome3 [[], {}]
        endif

    2、判断bool
        比如
        if (a>5) {
            print(5);
        } else {
            print(a);
        }
        转化为
        if ?&a>5
            print 5
        else
            print &a
        endif





7、循环       
    1、for循环
        1、in range
            比如
            ```
            for (i in range(1,5)) {
                for (j in range(1,6)) {
                    print(i+j);
                }
            }
            ```
            转化为
            loop l65196047842903732761  # 6519604784290373276 是整个文件的哈希，后面的1表示第几个loop节点
                set j 1                                     
                jmp l65196047842903732762                   

                set i &i+1                                  #  倒数第四行是for遍历对象操作
                if ?&i<5                                    #  倒数第三行判断是否继续for循环
                    jmp l65196047842903732761               #  倒数第二行jmp继续循环
                endif
            exit l65196047842903732761

            loop l65196047842903732762
                print &i+&j
                
                set j &j+1
                if ?&j<6
                    jmp ll65196047842903732761
                endif
            exit l65196047842903732762

            set i 1
            jmp l65196047842903732761

        2、in array
            比如
            ```
            for (i in [1,3,5]) {
                print(i);
            }
            ```
            转化为
            ```
            loop l65196047842903732761
                set i &a65196047842903732761[i65196047842903732761]
                print i

                set i65196047842903732761 &i65196047842903732761+1
                if ?&i65196047842903732761 < &g65196047842903732761  #  这里为了注释能让人看懂加了空格，实际是不加的
                    jmp l65196047842903732761
                endif
            exit l65196047842903732761

            set i65196047842903732761 1
            set a65196047842903732761 [1,3,5]
            set g65196047842903732761 a65196047842903732761@length  #  用@取属性
            jmp l65196047842903732761

    2、while循环
        比如
        ```
        while i<3:
            i = i^2;
        ```
        转化为
        loop l65196047842903732761
            set i &i^2

            if ?&i<3
                jmp l65196047842903732761
            endif
        exit l65196047842903732761


! 此函数是解析代码的主函数

*/
std::vector<std::string> handle_one_line(std::string newline) {
    std::vector<std::string> tokens_of_the_line = split(newline, " ");
    // the answer
    std::vector<std::string> answer;
    if (tokens_of_the_line.size() == 0) {
        return {};
    }
    std::string operation = tokens_of_the_line[0];
    if (isin(operation, KEY_WORDS)) {
        // this means that this line of code is used to define a function or a class // 此行为定义函数或类
        // either to import something // 或者import
        // TODO
        return {};
    } else {
        // this means that this line of code is used to evaluate a variable // 此行为赋值操作
        // or execute a function // 或者执行一个函数
        std::string end_of_line;
        int length_of_line = newline.length();
        end_of_line.push_back(newline[length_of_line - 1]);
        try {
            if (get_fiffle_op(end_of_line) == SP) {
                // 判断单行代码类型
                // 只能是变量赋值or执行函数
                // 所以依次获取char，遇到等号或左括号结束
                for(int index=0; index<newline.size()-1; index++) {
                    char current = newline[index];
                    // 跳过空格
                    if(isin(current, NONE)) {
                        continue;
                    }
                    if(current=='=') {
                        answer = _compile_evaluate(newline);
                    } else if (current == '(') {
                        answer = _compile_execute(newline);
                    }

                }
            } // TODO else if () {
            else {
                throw SyntaxError("Excepting seperator ';' but not found.");
            }
        }
        catch (std::out_of_range _) {
            throw SyntaxError("Excepting seperator ';' but not found.");
        }
    }
    return answer;
}
// int main() {
//     auto a = std::chrono::steady_clock::now();
//     try {
//         std::string code = "a=4+5*60;";
//         std::vector<std::string> tokens = handle_one_line(code);
//         for(std::string token : tokens) {
//             std::cout<< token<< ", " ;
//         }
//     } catch (std::exception& e) {
//         std::cout << e.what() << std::endl;
//     }

//     auto b = std::chrono::steady_clock::now();
//     std::cout << std::chrono::duration<double, std::micro>(b-a).count();
//     return 0;
// }