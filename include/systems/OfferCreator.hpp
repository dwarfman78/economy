#ifndef ECONOMY_OFFERCREATOR_HPP
#define ECONOMY_OFFERCREATOR_HPP
#include "../Common.hpp"
#include "../components/Agent.hpp"
class OfferCreator : public entityx::System<OfferCreator> {
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt);
};
#endif