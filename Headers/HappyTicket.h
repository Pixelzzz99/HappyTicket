#pragma once 
#include <vector>
#include "StrategyVariant.h"

class HappyTicket
{
private:
    StrategyVariant* strategy_;
public:
    HappyTicket(StrategyVariant* strategy = nullptr);
    ~HappyTicket();

    std::vector<int> DoAlgorithm();
    int getCountOfDigits_N();
    int getBase_D();
};

