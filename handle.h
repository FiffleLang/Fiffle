#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <stack>
#include <map>

class Node {
public:
	double num = 0; //操作数
	char op = '+'; //操作符
	bool isop; //true表示操作符，false表示操作数

	Node(int num, bool isop) {
		this->num = num;
		this->isop = false;
	};
	Node(char op, bool isop) {
		this->op = op;
		this->isop = true;
	}
};


std::vector<std::string> split(std::string string, std::string delimeter=" ", int start=0, int end=-1);
std::vector<std::string> split_and_keep(std::string string, char delimeter, int start=0, int end=-1);

std::vector<std::string> handle_one_line(std::string newline);

bool isin(int element, std::vector<int> list);
bool isin(std::string element, std::vector<std::string> list);
bool isin(char element, std::vector<char> list);
bool isin(char element, std::string list);

char islegal(std::string name);

void print(std::string message);
void print(std::string message, bool iferror);

std::vector<Node> midToBack(std::string mid);
double getValue(std::vector<Node> back);
double calculate(std::string expression);


const std::string S1 = "!";
const std::string S2 = "@";
const std::string S3 = "#";
const std::string S4 = "$";
const std::string S5 = "%";
const std::string S6 = "^";
const std::string S7 = "&";
const std::string S8 = "*";
const std::string LEFT_S = "(";
const std::string RIGHT_S = ")";
const std::string MINUS = "-";
const std::string UNDER = "_";
const std::string ADDIT = "+";
const std::string EQUAL = "=";
const std::string LEFT_M = "[";
const std::string RIGHT_M = "]";
const std::string LEFT_B = "{";
const std::string RIGHT_B = "}";
const std::string GD = "|";
const std::string LT2RB = "\\";
const std::string LB2RT = "/";
const std::string COMMA = ",";
const std::string PERIOD = "@";
const std::string LGT = "<";
const std::string RGT = ">";
const std::string WHAT = "?";
const std::string ABOUT = "~";
const std::string DIAN = "`";
const std::string SP = ";";
const std::string MEAN = ":";
const std::string DYH = "'";
const std::string SYH = "\"";

const std::string LGT_EQUAL = "<=";
const std::string RGT_EQUAL = ">=";
const std::string NOT_EQUAL = "!=";
const std::string IS_EUQAL = "==";


const std::vector<std::string> SPECIAL_ASCII = {
    S1, S2, S3, S4, S5, S6, S7, S8, LEFT_S, RIGHT_S, LEFT_B, RIGHT_B, LEFT_M, RIGHT_M, MINUS
};

const std::string NUMBERS = "0123456789";
const std::string CALCULATORS = "+-/*()";
const std::string ILEGAL_CHARS = "!@#$%^&*()-+[]{};:'\"`~,./?<>|\\/*";

/*
和python一样，int等类型都不是关键字，是内置类型
Key Words:
    public private internal
    if else elif
    func class
    for while
    break continue breakall
    import from as functions variables consts classes everything
*/
const std::string PUBLIC="public", PRIVATE="private", INTERNAL="internal", IF="if", ELSE="else", ELIF="elif", FUNC="func", CLASS="class", FOR="for", WHILE="while", BREAK="break", CONTINUE="continue", BREAKALL="breakall", IMPORT="import", FROM="from", AS="as", FUNCTIONS="functions", VARIABLES="variables", CONSTS="consts", CLASSES="classes", EVERYTHING="everything";

const std::vector<std::string> KEY_WORDS = {PUBLIC, PRIVATE, INTERNAL, IF, ELSE, ELIF, FUNC, CLASS, FOR, WHILE, BREAK, CONTINUE, BREAKALL, IMPORT, FROM, AS, FUNCTIONS, VARIABLES, CONSTS, CLASSES, EVERYTHING};

const std::vector<std::string> SCOPES = {PUBLIC, PRIVATE, INTERNAL};
const std::vector<std::string> JUDGES = {IF, ELSE, ELIF};
const std::vector<std::string> DEFINE = {FUNC, CLASS};
const std::vector<std::string> LOOPER = {FOR, WHILE};
const std::vector<std::string> JUMPER = {BREAK, CONTINUE, BREAKALL};
const std::vector<std::string> IMPORTION = {IMPORT, FROM, AS, FUNCTIONS, VARIABLES, CONSTS, CLASSES, EVERYTHING};


