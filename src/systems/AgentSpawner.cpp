#include "../../include/systems/AgentSpawner.hpp"
void AgentSpawner::configure(entityx::EntityManager &es, entityx::EventManager &events)
{
    for(int i=0; i<Utils::randomBetween(3,3); ++i)
    {
        entityx::Entity agent = es.create();

        auto products = createProducts();

        auto demands = createDemands(es);

        agent.assign<Agent>(products,demands);
    }
}
void AgentSpawner::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{

}
std::vector< std::shared_ptr<Product> > AgentSpawner::createProducts()
{
    std::vector < std::shared_ptr<Product> > retour;

    std::shared_ptr<Product> product = std::make_shared<Product>();

    retour.push_back(product);

    return std::move(retour);
}

std::vector< std::shared_ptr<Demand> > AgentSpawner::createDemands(entityx::EntityManager &es) {
    std::vector< std::shared_ptr<Demand> > retour;

    std::shared_ptr<Product> productNeeded = nullptr;

    es.each<Agent>([&productNeeded](entityx::Entity entity, Agent& agent) {
        auto lastProduct = agent.getProducts().back();
        if(lastProduct!=nullptr)
        {
            productNeeded = lastProduct;
        }
    });

    if(productNeeded!= nullptr)
    {
        std::shared_ptr<Demand> demand = std::make_shared<Demand>(productNeeded, 1);

        retour.push_back(demand);
    }

    return std::move(retour);
}
