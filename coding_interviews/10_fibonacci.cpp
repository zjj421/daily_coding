//
// Created by zj on 20-5-11.
//
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
/*
 * 题目一：求斐波那契数列的第n项。
 * 写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。斐波那契数列的定义如下：
 *          0,                  n=0
 * f(n) =   1,                  n=1
 *          f(n-1) + f(n-2),    n>1
 *
 * */


//1. 递归
/*
 * 时间复杂度: O(2^n)
 * 空间复杂度: O(n)
 * */
long long fibonacci_recursive(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

//2.遍历
/*
 * 从下往上计算，首先根据f(0)和f(1)计算出f(2)，再根据f(1)和f(2)计算出f(3)...以此类推。
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 * */
long long fibonacci(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    long long fib_2 = 0;
    long long fib_1 = 1;
    long long fib_n = -1;
    unsigned int i = 2;
    while (i <= n)
    {
        fib_n = fib_1 + fib_2;
        fib_2 = fib_1;
        fib_1 = fib_n;
        ++i;
    }
    return fib_n;

}


class Test
{
public:
    void test_fibonacci()
    {
        int n = 50;
        vector<unsigned int> lst;
        for(int i=0;i<n;++i)
        {
            lst.push_back(i);
        }


        cout << "fib(" << n << "): " << endl;
        auto time_start = system_clock::now();;
        for(auto &it:lst)
        {

            cout << fibonacci_recursive(it) << ", ";
        }
        auto time_end = system_clock::now();;
        auto duration = duration_cast<microseconds>(time_end-time_start);
        cout << endl << "time: " << duration.count() << " ms" << endl;

        time_start = system_clock::now();;
        for(auto &it:lst)
        {

            cout << fibonacci(it) << ", ";
        }
        time_end = system_clock::now();;
        duration = duration_cast<microseconds>(time_end-time_start);
        cout << endl << "time: " << duration.count() << " ms" << endl;



    }
};

int main()
{
    Test test_obj;
    test_obj.test_fibonacci();
    return 0;
}


