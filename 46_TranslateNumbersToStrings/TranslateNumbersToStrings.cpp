/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met :
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and / or other materials provided with the distribution.
    * Neither the name of Harry He nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

#include <string>
#include <iostream>

using namespace std;

int GetTranslationCount(const string& number);

int GetTranslationCount(int number)
{
    if(number < 0)
        return 0;

    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count = 0;

    for(int i = length - 1; i >= 0; --i)
    {
        count = 0;
         if(i < length - 1)
               count = counts[i + 1];
         else
               count = 1;

        if(i < length - 1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25)
            {
                if(i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }

    count = counts[0];
    delete[] counts;

    return count;
}

// ====================测试代码====================
void Test(const string& testName, int number, int expected)
{
    if(GetTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
