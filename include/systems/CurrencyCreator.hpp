#ifndef ECONOMY_CURRENCYCREATOR_HPP
#define ECONOMY_CURRENCYCREATOR_HPP
#include "../Common.hpp"
#include "../components/Agent.hpp"
class CurrencyCreator : public entityx::System<CurrencyCreator>
{
public:
    void configure(entityx::EntityManager &es, entityx::EventManager &events);
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt);
private:
    chaiscript::ChaiScript mChai;
};
#endif