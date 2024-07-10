import sys
if len(sys.argv) <= 2:
    print("参数不足，需要filename和主函数名称！")
    exit()

filename = sys.argv[1]
mainfunction = sys.argv[2]

if len(sys.argv) == 2:
    args = ()
else:
    args = str(tuple(sys.argv[3:]))

with open("./%s_main.cpp"%filename, "w") as f:
    f.write('''
#include "%s.cpp"
int main() {
    %s%s;
}'''%(filename, mainfunction, args))
print("OK")