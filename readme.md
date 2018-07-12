##Valgrind是一款用于内存调试、内存泄漏检测以及性能分析的软件开发工具##
#### 官网:http://valgrind.org/
#### 用户开发手册地址:http://valgrind.org/docs/manual/manual.html


下载安装步骤：
> ① git clone git@github.com:meihao1203/Valgrind
> （git clone https://github.com/meihao1203/Valgrind）
> ② tar -xvzf valgrind-3.13.0.tar.gz
> ③ cd valgrind-3.13.0
> ④ make
> ⑤ sudo make install

查看是否安装成功:
> valgrind --version
> `      显示 valgrind-3.13.0 即为成功`

valgrind --help   (查看帮助)

Demo小例子
```C++
 ///
 /// @file    uninit.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-12 19:59:17
 ///
 
#include<iostream>
using namespace std;
int main(int argc,char** argv)
{
	int* arr = new int[5];  //没有释放，内存泄露
	return 0;
}
```
编译：
> g++ -g uninit.cpp

使用valgrind调试,显示出详细的内存泄露信息，以及错误发生在哪一行
> valgrind --tool=memcheck --leak-check=full ./a.out
```C++
//==18626== Memcheck, a memory error detector
//==18626== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
//==18626== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
//==18626== Command: ./a.out
//==18626== 
//==18626== 
//==18626== HEAP SUMMARY:
//==18626==     in use at exit: 72,724 bytes in 2 blocks
//==18626==   total heap usage: 2 allocs, 0 frees, 72,724 bytes allocated
//==18626== 
//==18626== 20 bytes in 1 blocks are definitely lost in loss record 1 of 2
//==18626==    at 0x4C2E8BB: operator new[](unsigned long) (vg_replace_malloc.c:423)
//==18626==    by 0x400717: main (uninit.cpp:11)
//==18626== 
//==18626== LEAK SUMMARY:
//==18626==    definitely lost: 20 bytes in 1 blocks
//==18626==    indirectly lost: 0 bytes in 0 blocks
//==18626==      possibly lost: 0 bytes in 0 blocks
//==18626==    still reachable: 72,704 bytes in 1 blocks
//==18626==         suppressed: 0 bytes in 0 blocks
//==18626== Reachable blocks (those to which a pointer was found) are not shown.
//==18626== To see them, rerun with: --leak-check=full --show-leak-kinds=all
//==18626== 
//==18626== For counts of detected and suppressed errors, rerun with: -v
//==18626== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

valgrind --help对应的中文
```C++
用法: valgrind [options] prog-and-args
[options]: 常用选项，适用于所有Valgrind工具

    -tool=<name> 最常用的选项。运行 valgrind中名为toolname的工具。默认memcheck。
        memcheck ------> 这是valgrind应用最广泛的工具，一个重量级的内存检查器，能够发现开发中绝大多数内存错误使用情况，比如：使用未初始化的内存，使用已经释放了的内存，内存访问越界等。
        callgrind ------> 它主要用来检查程序中函数调用过程中出现的问题。
        cachegrind ------> 它主要用来检查程序中缓存使用出现的问题。
        helgrind ------> 它主要用来检查多线程程序中出现的竞争问题。
        massif ------> 它主要用来检查程序中堆栈使用中出现的问题。
        extension ------> 可以利用core提供的功能，自己编写特定的内存调试工具

    -h –help 显示帮助信息。
    -version 显示valgrind内核的版本，每个工具都有各自的版本。
    -q –quiet 安静地运行，只打印错误信息。
    -v –verbose 更详细的信息, 增加错误数统计。
    -trace-children=no|yes 跟踪子线程? [no]
    -track-fds=no|yes 跟踪打开的文件描述？[no]
    -time-stamp=no|yes 增加时间戳到LOG信息? [no]
    -log-fd=<number> 输出LOG到描述符文件 [2=stderr]
    -log-file=<file> 将输出的信息写入到filename.PID的文件里，PID是运行程序的进行ID
    -log-file-exactly=<file> 输出LOG信息到 file
    -log-file-qualifier=<VAR> 取得环境变量的值来做为输出信息的文件名。 [none]
    -log-socket=ipaddr:port 输出LOG到socket ，ipaddr:port

LOG信息输出

    -xml=yes 将信息以xml格式输出，只有memcheck可用
    -num-callers=<number> show <number> callers in stack traces [12]
    -error-limit=no|yes 如果太多错误，则停止显示新错误? [yes]
    -error-exitcode=<number> 如果发现错误则返回错误代码 [0=disable]
    -db-attach=no|yes 当出现错误，valgrind会自动启动调试器gdb。[no]
    -db-command=<command> 启动调试器的命令行选项[gdb -nw %f %p]

适用于Memcheck工具的相关选项：

    -leak-check=no|summary|full 要求对leak给出详细信息? [summary]
    -leak-resolution=low|med|high how much bt merging in leak check [low]
    -show-reachable=no|yes show reachable blocks in leak check? [no]
```