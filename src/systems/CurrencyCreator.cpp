#include "../../include/systems/CurrencyCreator.hpp"
void CurrencyCreator::configure(entityx::EntityManager &es, entityx::EventManager &events)
{
    es.each<Agent>([this](entityx::Entity entity, Agent &agent) {

    });
}
void CurrencyCreator::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{

}