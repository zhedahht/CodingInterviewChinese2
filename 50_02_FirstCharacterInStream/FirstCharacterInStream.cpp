/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

class CharStatistics
{
public:
    CharStatistics() : index(0)
    {
        for(int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }

    void Insert(char ch)
    {
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }

    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i = 0; i < 256; ++i)
        {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char) i;
                minIndex = occurrence[i];
            }
        }

        return ch;
    }

private:
    // occurrence[i]: A character with ASCII value i;
    // occurrence[i] = -1: The character has not found;
    // occurrence[i] = -2: The character has been found for mutlple times
    // occurrence[i] >= 0: The character has been found only once
    int occurrence[256];
    int index;
};

// ====================测试代码====================
void Test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}

