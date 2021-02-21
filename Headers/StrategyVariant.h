#pragma once
#include <vector>
#include "GeneratorTasks.h"

class StrategyVariant
{
private:
    int _countOfDigits_N;
    int _base_D;
public:
    int getCountOfDigits_N();
    void setCountOfDigits_N(int);

    int getBase_D();
    void setBase_D(int);

    virtual ~StrategyVariant() = default;
    virtual std::vector<int> solve() = 0;
};
