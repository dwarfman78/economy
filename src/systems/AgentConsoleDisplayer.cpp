#include "../../include/systems/AgentConsoleDisplayer.hpp"
void AgentConsoleDisplayer::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    es.each<Agent>([](entityx::Entity entity, Agent& agent) {

        std::cout << "Agent : " << agent.getId()  << std::endl;

        std::cout << "\t currencies : " << agent.getCurrencies() << std::endl;

        for(auto& demand : agent.getDemands())
        {
            std::cout << "\t Sustain Demands : " << demand->getProduct()->getId() << " : " << demand->getQuantity() << std::endl;
        }

        for(auto& product : agent.getProducts())
        {
            std::cout << "\t Products : " << product->getId() << std::endl;

            for(auto& productDemand : product->getDemands())
            {
                std::cout << "\t\t Product demand : " << productDemand->getProduct()->getId() << " : " << productDemand->getQuantity() << std::endl;
            }
        }

        for(auto& offer : agent.getOffers())
        {
            std::cout << "\t Offers : " << offer->getProduct()->getId() << " : " << offer->getQuantity() << std::endl;
        }

        std::cout << std::endl;

    });
}