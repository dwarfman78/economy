#include "../../include/systems/MarketResolver.hpp"
void MarketResolver::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    es.each<Agent>([this,&es](entityx::Entity entity, Agent& agent) {

        for(auto& demand : agent.getDemands())
        {
            resolvDemand(agent,demand,es);
        }

    });
}

void MarketResolver::resolvDemand(Agent& pAgent, std::shared_ptr<Demand> pDemand, entityx::EntityManager& pEs)
{

    std::shared_ptr<Offer> bestOffer = nullptr;

    // Not proud of this Agent*
    Agent* agentOffer = nullptr;

    pEs.each<Agent>([&pAgent,&pDemand,&bestOffer,&agentOffer](entityx::Entity entity, Agent& agent) {
        if(pAgent.getId()!=agent.getId())
        {
            auto offerByProductId = agent.getOffersByProductId();
            auto offerPair = offerByProductId.find(pDemand->getProduct()->getId());

            if(offerPair!=offerByProductId.end())
            {
                auto offer = offerPair->second;

                if(offer->getQuantity()>=pDemand->getQuantity())
                {
                    unsigned int finalPrice = offer->getPrice() * pDemand->getQuantity();

                    if(pAgent.getCurrencies()>=finalPrice)
                    {
                        if(bestOffer==nullptr || (bestOffer!=nullptr && bestOffer->getPrice()>offer->getPrice()))
                        {
                            bestOffer = offer;
                            agentOffer = &agent;
                        }
                    }
                }
            }
        }
    });

    if(bestOffer!=nullptr&&agentOffer!=nullptr)
    {
        unsigned int finalPrice = bestOffer->getPrice() * pDemand->getQuantity();

        pAgent.subCurrency(finalPrice);
        bestOffer->subQuantity(pDemand->getQuantity());
        agentOffer->addCurrency(finalPrice);

    }
}