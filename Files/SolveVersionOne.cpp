#include "SolveVersionOne.h"

SolveVersionOne::SolveVersionOne(GeneratorTasks test)
{
    setCountOfDigits_N(test.getDigits_N());
    setBase_D(test.getBase_D());
    dpResize();
}

SolveVersionOne::SolveVersionOne(int N, int D)
{
    setCountOfDigits_N(N);
    setBase_D(D);
    dpResize();
}

void SolveVersionOne::dpResize()
{
    int n = getCountOfDigits_N();
    int d = getBase_D();
    dp.resize(n + 2);
    for (int i = 0; i < n + 2; i++)
    {
        dp[i].resize(n * (d + 1));
    }
}

std::vector<int> SolveVersionOne::solve()
{
    for (int i = 0; i <= getCountOfDigits_N(); i++)
    {
        for (int j = 0; j <= (getCountOfDigits_N() * (getBase_D() - 1)); j++)
        {
            dp[0][0].push_back(0);
        }
    }
    dp[0][0].pop_back();
    dp[0][0].push_back(1);

    for (int pos = 1; pos <= getCountOfDigits_N(); pos++)
    {
        for (int sum = 0; sum <= (getCountOfDigits_N() * (getBase_D() - 1)); sum++)
        {
            for (int now_digit = 0; now_digit <= (getBase_D() - 1); now_digit++)
            {
                if (sum + now_digit <= (getCountOfDigits_N() * (getBase_D() - 1)))
                {
                    dp[pos][sum + now_digit] = add(dp[pos][sum + now_digit], dp[pos - 1][sum], getBase_D());
                }
            }
        }
    }

    std::vector<int> answer = {0};
    for (int i = 0; i <= (getCountOfDigits_N() * (getBase_D()-1)); i++)
    {
        answer = add(answer, multiplication(dp[getCountOfDigits_N()][i], dp[getCountOfDigits_N()][i], getBase_D()), getBase_D());
    }
    return answer;
}

std::vector<int> SolveVersionOne::add(std::vector<int> a, std::vector<int> b, int base)
{
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    if (b.size() > a.size())
    {
        swap(b, a);
    }

    std::vector<int> c;
    int del = 0;
    for (int i = 0; i < b.size(); i++)
    {
        int x = (b[i] + a[i] + del) % base;
        del = (b[i] + a[i] + del) / base;
        c.push_back(x);
    }
    
    for (int i = b.size(); i < a.size(); i++)
    {
        int x = (a[i] + del) % base;
        del = (a[i] + del) / base;
        c.push_back(x);
    }
    if (del > 0)
    {
        c.push_back(1);
    }
    std::reverse(c.begin(), c.end());
    return c;
}

std::vector<int> SolveVersionOne::multiplication(std::vector<int> a, std::vector<int> b, int base)
{
    std::vector<int> result;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    if (a.size() < b.size())
    {
        swap(a, b);
    }
    int now_summer = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int ind = 0;
        while (ind <= i && ind < b.size())
        {
            now_summer += b[ind] * a[i - ind];
            ind++;
        }
        result.push_back(now_summer % base);
        now_summer /= base;
    }
    
    for (int i = 1; i < b.size(); i++)
    {
        int ind = i; 
        int ind1 = a.size() - 1;
        while (ind < b.size() && ind1 >= 0)
        {
            now_summer += b[ind] * a[ind1];
            ind++;
            ind1++;
        }
        result.push_back(now_summer % base);
        now_summer /= base;
    }

    if (now_summer > 0) 
    {
        result.push_back(now_summer);
    }
    while (result.size() > 0 && result.back() == 0) 
    {
        result.pop_back();
    }
    if (result.size() == 0)
    {
        result.push_back(0);
    }
    std::reverse(result.begin(), result.end());

    return result;    
}
