//
// Created by dwarf on 19/03/2021.
//
#include "../../include/components/Agent.hpp"
unsigned int Agent::nextId=0;
void Agent::addOffer(std::shared_ptr<Offer> pOffer)
{
    auto oldOffer = mOffers.find(pOffer->getProduct()->getId());

    if(oldOffer != mOffers.end())
    {
        oldOffer->second->addQuantity(pOffer->getQuantity());
    }
    else
    {
        mOffers.insert(std::make_pair(pOffer->getProduct()->getId(), pOffer));
    }
}
std::vector<std::shared_ptr<Product> > Agent::getProducts()
{
    std::vector<std::shared_ptr<Product> > retour;

    for(auto& p : mProducts)
    {
        retour.push_back(p.second);
    }

    return std::move(retour);
}

std::vector<std::shared_ptr<Demand> > Agent::getDemands()
{
    std::vector<std::shared_ptr<Demand> > retour;

    for(auto& d : mDemands)
    {
        retour.push_back(d.second);
    }

    return std::move(retour);
}

std::vector<std::shared_ptr<Offer> > Agent::getOffers()
{
    std::vector<std::shared_ptr<Offer> > retour;

    for(auto& o : mOffers)
    {
        retour.push_back(o.second);
    }

    return std::move(retour);
}

