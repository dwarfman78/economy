#ifndef ECONOMY_DEMAND_HPP
#define ECONOMY_DEMAND_HPP
#include "Product.hpp"
class Product;
class Demand
{
public:
    Demand(std::shared_ptr<Product> pProduct, unsigned int pQuantity):mProduct(pProduct),mQuantity(pQuantity){}
    std::shared_ptr<Product> getProduct(){return mProduct;}
    unsigned int getQuantity(){return mQuantity;}
private:
    unsigned int mQuantity;
    std::shared_ptr<Product> mProduct;
};
#endif