@echo off
setlocal enabledelayedexpansion
chcp 65001

echo 欢迎使用 ITea 编译器配套编译命令行；输入help获取帮助=^)
:loop
    echo.
    echo | set /p=">>>"
    set input=
    set /p input=

    if "%input%"=="end" (
        break 
    ) else (
        if "%input:~0,6%"=="delcpp" (
            echo | set /p="删除 %input:~7,100%.cpp ...  "
            @del %input:~7,100%.cpp
            echo OK
            echo | set /p="删除 %input:~7,100%.exe ...  "
            @del %input:~7,100%.exe
            echo | set /p="删除 %input:~7,100%.o ...  "
            @del %input:~7,100%.o
        ) else (
            if "%input:~0,3%"=="del" (
                @del %input:~4,100%.o
                @del %input:~4,100%.exe
            )             
        )

        if "%input:~0,7%"=="commain" (
            echo | set /p="编译 %input:~8,100%_main.cpp -> %input:~8,100%_main.exe ...  "
            g++ %input:~8,100%_main.cpp -o %input:~8,100%_main.exe
            echo OK
        ) else (
            if "%input:~0,3%"=="com" (
                echo | set /p="编译 %input:~4,100%.cpp -> %input:~4,100%.exe ...  "
                g++ %input:~4,100%.cpp -o %input:~4,100%.exe
                echo OK
                echo | set /p="编译 %input:~4,100%.cpp -> %input:~4,100%.o ...  "
                echo OK
                g++ -c %input:~4,100%.cpp -o %input:~4,100%.o            
            )
        )
        
        if "%input:~0,4%"=="help" (
            echo help -^> 输出本帮助信息并继续
            echo end -^> 结束本命令行进程
            echo del xxx -^> 删除 xxx.o 和 xxx.exe ^(不删除cpp源文件^)
            echo com xxx -^> 编译 xxx.cpp ^(会同时编译可执行版本和链接文件^)
            echo run xxx -^> 运行 xxx.exe
            echo ------------------------------
            echo delcpp xxx -^> 删除 xxx.cpp
            echo commain xxx -^> 编译 xxx_main.cpp ^(仅生成exe版本供测试，生成链接文件请使用com命令^)
            echo makemain xxx yyy -^> 为 xxx.cpp 中的 yyy 函数生成一个测试版本的cpp文件
            echo runmain xxx -^> 运行 xxx_main.exe
            echo ------------------------------
            echo 请注意, 文件名长度不能超过100, 否则会被自动截断
        )
        if "%input:~0,8%"=="makemain" (
            echo | set /p="开始编写 ...  "
            python ./make_main.py %input:~9,200%
        )
        if "%input:~0,7%"=="runmain" (
            %input:~8,100%_main.exe
        ) else (
            if "%input:~0,3%"=="run" (
             %input:~4,100%.exe
            )
        )
        goto loop
    )

    
