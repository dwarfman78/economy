#ifndef ECONOMY_MARKETRESOLVER_HPP
#define ECONOMY_MARKETRESOLVER_HPP
#include "../Common.hpp"
#include "../components/Agent.hpp"
class MarketResolver : public entityx::System<MarketResolver>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt);
private:
    void resolvDemand(Agent& pAgent, std::shared_ptr<Demand> pDemand, entityx::EntityManager& pEs);
};
#endif