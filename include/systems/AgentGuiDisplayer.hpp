//
// Created by dwarf on 01/04/2021.
//
#ifndef ECONOMY_AGENTGUIDISPLAYER_HPP
#define ECONOMY_AGENTGUIDISPLAYER_HPP
#include "../Common.hpp"
#include "../components/Agent.hpp"
class AgentGuiDisplayer : public entityx::System<AgentGuiDisplayer>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt);
    void configure(entityx::EntityManager &es, entityx::EventManager &events);
private:
    unsigned int mCurrentPlot = 0;
    double mXplot[100];
    double mTotalCurrencies[100];
    std::map<unsigned int, std::vector<double> > mCurrencyByAgent;
};
#endif //ECONOMY_AGENTGUIDISPLAYER_HPP
