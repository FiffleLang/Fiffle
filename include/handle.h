#include <cmath>
#include <chrono>
#include <stack>
#include <map>

#include "handled.h"

class Node {
public:
  bool isop;      // true表示操作符，false表示操作数
  double num = 0; // 操作数
  char op = '+';  // 操作符

  /// @brief 实例化一个操作数节点
  /// @param num 操作数
  Node(int num) {
    this->num = num;
    this->isop = false;
  }
  
  /// @brief 实例化一个操作符节点
  /// @param op 操作符
  Node(char op) {
    this->op = op;
    this->isop = true;
  }
};

class SyntaxError
{
    public:
    SyntaxError(const std::string &error_msg) : _error_msg(error_msg) {}
    virtual std::string what() const
    {
        std::cout << _error_msg <<std::endl;
        return "SyntaxError: " + _error_msg;
    }

    protected:
        std::string _error_msg;
};

std::vector<std::string> split(std::string string, std::string delimeter = " ", int start = 0, int end = -1);
std::vector<std::string> split_and_keep(std::string string, char delimeter, int start = 0, int end = -1);



template <typename T, typename K>
bool isin(T element, K list);

char islegal(std::string name);

void print(std::string message);
void print(std::string message, bool iferror);

std::vector<Node> midToBack(std::string mid);
double getValue(std::vector<Node> back);
double calculate(std::string expression);

enum FiffleOpeator {
  S1,    S2,        S3,        S4,        S5,      S6,
  S7,    LEFT_S,    RIGHT_S,   MINUS,     UNDER,   ADDIT,
  EQUAL, LEFT_M,    RIGHT_M,   LEFT_B,    RIGHT_B, GD,
  LT2RB, LB2RT,     COMMA,     PERIOD,    LGT,     RGT,
  WHAT,  ABOUT,     DIAN,      SP,        MEAN,    DYH,
  SYH,   LGT_EQUAL, RGT_EQUAL, NOT_EQUAL, IS_EUQAL,
};

/*
Obtain the enum by using the token of the char type
*/
const std::map<std::string, FiffleOpeator> _get_fiffle_op = {
    {"!", FiffleOpeator::S1},         {"#", FiffleOpeator::S2},         {"$", FiffleOpeator::S3},      {"%", FiffleOpeator::S4},
    {"^", FiffleOpeator::S5},         {"&", FiffleOpeator::S6},         {"*", FiffleOpeator::S7},      {"(", FiffleOpeator::LEFT_S},
    {")", FiffleOpeator::RIGHT_S},    {"-", FiffleOpeator::MINUS},      {"_", FiffleOpeator::UNDER},   {"+", FiffleOpeator::ADDIT},
    {"=", FiffleOpeator::EQUAL},      {"[", FiffleOpeator::LEFT_M},     {"]", FiffleOpeator::RIGHT_M}, {"{", FiffleOpeator::LEFT_B},  
    {"},", FiffleOpeator::RIGHT_B},   {"|", FiffleOpeator::GD},         {"\\", FiffleOpeator::LT2RB},  {"/", FiffleOpeator::LB2RT},
    {",", FiffleOpeator::COMMA},      {"<", FiffleOpeator::LGT},        {">", FiffleOpeator::RGT},     {"?", FiffleOpeator::WHAT},
    {"~", FiffleOpeator::ABOUT},      {"`", FiffleOpeator::DIAN},       {";", FiffleOpeator::SP},      {":", FiffleOpeator::MEAN},
    {"\'", FiffleOpeator::DYH},       {"\"", FiffleOpeator::SYH},       {"@", FiffleOpeator::PERIOD},  {"<=", FiffleOpeator::LGT_EQUAL},
    {">=", FiffleOpeator::RGT_EQUAL}, {"!=", FiffleOpeator::NOT_EQUAL}, {"==", FiffleOpeator::IS_EUQAL}
};



const std::vector<FiffleOpeator> SPECIAL_ASCII = {
    FiffleOpeator::S1, FiffleOpeator::S2, FiffleOpeator::S3, FiffleOpeator::S4,
    FiffleOpeator::S5, FiffleOpeator::S6, FiffleOpeator::S7, FiffleOpeator::LEFT_S,
    FiffleOpeator::RIGHT_S, FiffleOpeator::LEFT_B, FiffleOpeator::RIGHT_B,
    FiffleOpeator::LEFT_M, FiffleOpeator::RIGHT_M, FiffleOpeator::MINUS
};

const std::string NUMBERS = "0123456789";
const std::string CALCULATORS = "+-/*()";
const std::vector<char> ILEGAL_CHARS = {
    '!', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'
};
const std::string NONE = " \r\t\n";
const char EMPTY = ' ';
const char EQUAL_ = '=';
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
const std::string PUBLIC = "public", PRIVATE = "private", INTERNAL = "internal", IF = "if", ELSE = "else", ELIF = "elif", FUNC = "func", CLASS = "class", FOR = "for", WHILE = "while", BREAK = "break", CONTINUE = "continue", BREAKALL = "breakall", IMPORT = "import", FROM = "from", AS = "as", FUNCTIONS = "functions", VARIABLES = "variables", CONSTS = "consts", CLASSES = "classes", EVERYTHING = "everything", BY = "by";

const std::vector<std::string> KEY_WORDS = {PUBLIC, PRIVATE, INTERNAL, IF, ELSE, ELIF, FUNC, CLASS, FOR, WHILE, BREAK, CONTINUE, BREAKALL, IMPORT, FROM, AS, FUNCTIONS, VARIABLES, CONSTS, CLASSES, EVERYTHING, BY};

const std::vector<std::string> SCOPES = {PUBLIC, PRIVATE, INTERNAL};
const std::vector<std::string> JUDGES = {IF, ELSE, ELIF};
const std::vector<std::string> DEFINE = {FUNC, CLASS};
const std::vector<std::string> LOOPER = {FOR, WHILE};
const std::vector<std::string> JUMPER = {BREAK, CONTINUE, BREAKALL};
const std::vector<std::string> IMPORTION = {
    IMPORT, FROM, AS, FUNCTIONS, VARIABLES, CONSTS, CLASSES, EVERYTHING};
