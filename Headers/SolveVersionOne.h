#pragma once
#include "HappyTicket.h"
#include "GeneratorTasks.h"
#include <algorithm>
class SolveVersionOne : public HappyTicket
{
private:
    std::vector<std::vector<std::vector<int>>> dp;

    std::vector<int> multiplication(std::vector<int>, std::vector<int>, int);
    std::vector<int> add(std::vector<int>, std::vector<int>, int);
    void dpResize();
public:

    SolveVersionOne(GeneratorTasks);
    SolveVersionOne(int N, int D);
    ~SolveVersionOne() = default;
    
    std::vector<int> solve() override;
};