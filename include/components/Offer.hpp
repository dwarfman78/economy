#ifndef ECONOMY_OFFER_HPP
#define ECONOMY_OFFER_HPP
#include "Product.hpp"
class Offer
{
public:
    Offer(std::shared_ptr<Product> pProduct, unsigned int pQuantity, unsigned int pPrice, bool pSellable) :
    mProduct(std::move(pProduct)), mQuantity(pQuantity), mPrice(pPrice), mSellable(pSellable) {}
    std::shared_ptr<Product> getProduct(){return mProduct;}
    unsigned int getQuantity() const {return mQuantity;}
    void addQuantity(unsigned int pQuantity){mQuantity += pQuantity;}
    void subQuantity(unsigned int pQuantity){mQuantity -= pQuantity;}
    unsigned int getPrice(){return mPrice;}
private:
    unsigned int mQuantity;
    unsigned int mPrice;
    bool mSellable;
    std::shared_ptr<Product> mProduct;
};
#endif