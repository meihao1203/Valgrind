 ///
 /// @file    uninit.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-12 19:59:17
 ///
 
#include<iostream>
using namespace std;
int main()
{
	int* arr = new int[5];  //没有释放，内存泄露
	return 0;
}
/* 
 * g++ -g uninit.cpp 
 * valgrind --tool=memcheck --leak-check=full ./a.out 
 * 默认命令就是 --tool=memcheck  可以简写 valgrind --leak-check=full ./a.out 
 * 如果输出信息想要显示错误出现在哪一行，编译的时候要生成调试信息，加上 -g 命令
*/
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
