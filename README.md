# Fiffle

请注意，本文档只有<a href="https://github.com/FiffleLang/Fiffle/blob/main/docs/english.md">English</a>和<a href="https://github.com/FiffleLang/Fiffle/README.md">中文</a>两个官方人工翻译文档，其他文档为自动翻译或社区翻译，如有勘误，请以官方文档为准。如果英语和中文文档出现语义差别，请提交Issue让官方来处理。默认以中文文档为主。

<a href="https://github.com/FiffleLang/Fiffle/blob/main/docs/english.md">English</a> <a href="https://github.com/FiffleLang/Fiffle/README.md">中文（当前）</a>

Fiffle 是一个高性能的数据处理语言。它的设计用途是更快、更好地处理大量数据，而无需像`C++`那样编写大量复杂且难以理解的脚本，运行速度则优于`Python`。其具有高可读性和中等运行速度。

下面是一个示范的`example.fif`文件：

```fif
# 和Python一样，Fiffle采用井号进行单行注释，采用三引号进行多行注释
import everything from std; # everything 是fiffle特有的关键字，效用等同于Python中的 from std import *
import functions {get, post, } from requests; # functions 等是fiffle在import时使用的关键字，详见handle.h中定义的KEY_WORDS

func test(a, b) {
    """
    方法的定义可以不声明返回值，默认为 auto|void
    """
    print(a+b);
}

func main() { 
    """
    main方法为程序的入口，程序会自动调用main方法，如果该文件是被import的，则不会执行main函数
    """
    test(1, 2);
    print(add(1, 2));
}
```
请注意，Fiffle是一个半动态语言，因此虽然变量有特定类型，但是声明方法时字面声明的返回类型与实际类型可以不相符。