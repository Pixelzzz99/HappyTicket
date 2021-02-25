#pragma once
#include "StrategyVariant.h"

class SolveVersionTwo : public StrategyVariant
{
private:
    long long getMax(int length, int d);
    bool good(long long index, long long d, int length);
    std::vector<int> trans(long long x, long long d);
public:
    SolveVersionTwo(GeneratorTasks*);
    std::vector<int> solve() override;
};