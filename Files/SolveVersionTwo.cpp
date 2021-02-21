#include "SolveVersionTwo.h"
#include <string>
SolveVersionTwo::SolveVersionTwo(GeneratorTasks *test)
{
    setCountOfDigits_N(test->getDigits_N());
    setBase_D(test->getBase_D());
}

std::vector<int> SolveVersionTwo::solve()
{
    int n = getCountOfDigits_N();
    int d = getBase_D();

    long long maxNumber = getMax(n, d);
    int answer = 0;
    for (long long i = 0; i < maxNumber; i++)
    {
        if (good(i, d, 2 * n))
        {  
            answer++;
        }
    }
    return getLength(answer);
}

long long SolveVersionTwo::getMax(int length, int d)
{
    length *=  2;
    long long result = 1;
    while(length--)
    {
        result = result * (long long)1 * d;
    }
    return result;
}

bool SolveVersionTwo::good(long long index, long long d, int length)
{
    std::string result;
    for (int i = 0; i < length; i++)
    {
        result.push_back(char('0' + index % d));
        index /= d;
    }    
    int left = 0;
    int right = length - 1;
    while(left <= right)
    {
        if(result[left] !=  result[right]) return false;
        left++;
        right--;
    }
    return true;
}

std::vector<int> getLength(int x)
{
    std::vector<int> result;
    while(x>0)
    {
        result.push_back(x%10);
        x /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}