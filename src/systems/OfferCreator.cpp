#include "../../include/systems/OfferCreator.hpp"
void OfferCreator::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    es.each<Agent>([](entityx::Entity entity, Agent& agent) {
        auto offers = agent.getOffers();

        for(auto it = std::begin(offers); it != std::end(offers);)
        {
            auto offr = *it;

            if(offr->getQuantity() == 0)
            {
                offers.erase(it);
            } else
            {
                it++;
            }
        }
        for(auto& product : agent.getProducts())
        {
            if(product->isBasic())
            {
                auto offer = std::make_shared<Offer>(product,1,1,true);
                agent.addOffer(offer);
            }
        }
    });
}