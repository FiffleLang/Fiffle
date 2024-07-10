# Fiffle

Attention, documents of `Fiffle` only has <a href="https://FiffleLang/Fiffle/docs/english.md">English</a> and <a href="https://FiffleLang/Fiffle/README.md">中文</a>versions written or translated by fiffle.org, while other documents are translated automatically or by the developers' community. If there exists differences between official documents and others, the official ones first. If there are semantic differences between English and Chinese documents, please submit an Issue for the official to handle. The default format is Chinese documents.

<a href="https://FiffleLang/Fiffle/docs/english.md">English(Now)</a> <a href="https://FiffleLang/Fiffle/README.md">中文</a>

Fiffle is a high-performance data processing language. Its design purpose is to process large amounts of data faster and better, without writing complex and confusing scripts like C++, and its running speed is better than Python. It has high readability and moderate running speed.

Here is a demonstration file `example.fif`:

```fif
# like Python, fiffle use # to make an inline comment, and three quotation marks to make a multiline comment.
import everything from std; # `everything` is a keyword from fiffle, its meanings just like `from std import *` in Python
import functions {get, post, } from requests; # `functions` are keywords from fiffle while importing, more keywords can be found in handle.h/KEY_WORDS

func test(a, b) {
    """
    defination of functions can be without types, the default types will be set to auto||void.
    """
    print(a+b);
}

func int add(a, b) {
    """
    of course you can define it using special types like int (in fiffle, default-types are built-ins, not keywords)
    """
    return a+b;
}

func main() { 
    """
    function main is the entrance while running the fif-file. If you import it, the function won't be run.
    """
    test(1, 2);
    print(add(1, 2));
}
```