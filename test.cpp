#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);

    // 指定要打开的文件名和模式
    ifstream file("make_main.py", ios::in);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "无法打开文件！" << endl;
        return 1;
    }

    // 读取文件内容
    string content1;string content2;
    getline(file, content1);getline(file, content2);

    // 输出文件内容
    cout << "文件内容：\n" << content1 << content2 << endl;

    // 关闭文件
    file.close();

    return 0;
}
