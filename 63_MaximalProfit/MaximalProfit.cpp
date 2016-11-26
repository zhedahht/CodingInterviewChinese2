//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

#include <cstdio>

int MaxDiff(const int* numbers, unsigned length)
{
    if(numbers == nullptr && length < 2)
        return 0;

    int min = numbers[0];
    int maxDiff = numbers[1] - min;

    for(int i = 2; i < length; ++i)
    {
        if(numbers[i - 1] < min)
            min = numbers[i - 1];

        int currentDiff = numbers[i] - min;
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }

    return maxDiff;
}

// ==================== Test Code ====================
void Test(const char* testName, const int* numbers, unsigned int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(MaxDiff(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1()
{
    int numbers[] = { 4, 1, 3, 2, 5 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

void Test2()
{
    int numbers[] = { 1, 2, 4, 7, 11, 16 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

void Test3()
{
    int numbers[] = { 16, 11, 7, 4, 2, 1 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

void Test4()
{
    int numbers[] = { 9, 11, 5, 7, 16, 1, 4, 2 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 11);
}

void Test5()
{
    int numbers[] = { 2, 4 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), 2);
}

void Test6()
{
    int numbers[] = { 4, 2 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), -2);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
