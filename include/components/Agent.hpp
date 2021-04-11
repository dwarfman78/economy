#ifndef ECONOMY_AGENT_HPP
#define ECONOMY_AGENT_HPP
#include "../Common.hpp"
#include "Product.hpp"
#include "Offer.hpp"
class Agent
{
public:
    Agent(Agent&& pA)
    {
        std::cout << "Copy Move Agent ! " << std::endl;
    }
    Agent(const Agent& pA)
    {
        std::cout << "Copy Agent !" << std::endl;
    }
    Agent(std::vector< std::shared_ptr<Product> > pProducts, std::vector< std::shared_ptr<Demand> > pDemands):mId(Agent::getNextId())
    {
        std::transform(pProducts.begin(), pProducts.end(), std::inserter(mProducts, mProducts.end()),
                       [](const auto& product) { return std::make_pair(product->getId(), product); });

        std::transform(pDemands.begin(), pDemands.end(), std::inserter(mDemands, mDemands.end()),
                       [](const auto& demand) { return std::make_pair(demand->getProduct()->getId(), demand); });
    }
    void addOffer(std::shared_ptr<Offer> pOffer);

    void addCurrency(unsigned int pAmount){mCurrencies+=pAmount;}

    void subCurrency(unsigned int pAmount){mCurrencies-=pAmount;}

    unsigned int getId() const {return mId;}

    unsigned int getCurrencies(){return mCurrencies;}

    std::vector< std::shared_ptr<Product> > getProducts();

    std::vector< std::shared_ptr<Demand> > getDemands();

    std::vector< std::shared_ptr<Offer> > getOffers();

    std::map< unsigned int, std::shared_ptr<Demand> > getDemandsByProductId(){return mDemands;}

    std::map< unsigned int, std::shared_ptr<Offer> > getOffersByProductId(){return mOffers;}
private:
    unsigned int mId;
    unsigned int mCurrencies;
    std::map< unsigned int, std::shared_ptr<Demand> > mDemands;
    std::map< unsigned int, std::shared_ptr<Product> > mProducts;
    std::map< unsigned int, std::shared_ptr<Offer> > mOffers;
    static unsigned int nextId;
    static unsigned int getNextId(){Agent::nextId++;return Agent::nextId;}
};
#endif