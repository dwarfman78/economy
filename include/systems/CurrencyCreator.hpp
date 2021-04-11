#ifndef ECONOMY_CURRENCYCREATOR_HPP
#define ECONOMY_CURRENCYCREATOR_HPP
#include "../Common.hpp"
#include "../systems/ScriptableSystem.hpp"
class CurrencyCreator : public ScriptableSystem<CurrencyCreator>
{
public:
    CurrencyCreator() : ScriptableSystem("CurrencyCreator"){}
};
#endif