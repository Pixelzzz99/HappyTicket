#include "HappyTicket.h"

HappyTicket::HappyTicket(StrategyVariant* strategy) 
{
    this->strategy_ = strategy;
}

HappyTicket::~HappyTicket()
{
    delete strategy_;
}

std::vector<int> HappyTicket::DoAlgorithm()
{
    return strategy_->solve();
}

int HappyTicket::getCountOfDigits_N()
{
    return strategy_->getCountOfDigits_N();
}

int HappyTicket::getBase_D()
{
    return strategy_->getBase_D();
}


