#ifndef ECONOMY_AGENTSPAWNER
#define ECONOMY_AGENTSPAWNER
#include "../Common.hpp"
#include "../components/Agent.hpp"
#include "../Utils.hpp"
class AgentSpawner : public entityx::System<AgentSpawner>
{
public:
    void configure(entityx::EntityManager &es, entityx::EventManager &events);
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt);
private:
    std::vector< std::shared_ptr<Product> > createProducts();
    std::vector< std::shared_ptr<Demand> > createDemands(entityx::EntityManager &manager);
};
#endif