#ifndef ECONOMY_PRODUCT_HPP
#define ECONOMY_PRODUCT_HPP
#include "../Common.hpp"
#include "Demand.hpp"
class Product
{
public:
    Product():mId(Product::getNextId()){}
    Product(std::vector< std::shared_ptr<Demand> > pDemands):mId(Product::getNextId()), mDemands(std::move(pDemands)){}
    unsigned int getId(){return mId;}
    bool isBasic() const {return mDemands.size() == 0;}
    std::vector< std::shared_ptr<Demand> > getDemands(){return mDemands;}

private:
    unsigned int mId;
    std::vector< std::shared_ptr<Demand> > mDemands;
    static unsigned int nextId;
    static unsigned int getNextId(){Product::nextId++; return Product::nextId;}
};
#endif