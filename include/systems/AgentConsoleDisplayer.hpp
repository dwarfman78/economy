#ifndef ECONOMY_AGENTCONSOLEDISPLAYER_HPP
#define ECONOMY_AGENTCONSOLEDISPLAYER_HPP
#include "../Common.hpp"
#include "../components/Agent.hpp"
class AgentConsoleDisplayer : public entityx::System<AgentConsoleDisplayer>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt);
};
#endif