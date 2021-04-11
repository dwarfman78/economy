#ifndef ECONOMY_AGENTSPAWNER
#define ECONOMY_AGENTSPAWNER
#include "../Common.hpp"
#include "../../include/systems/ScriptableSystem.hpp"
#include "../Utils.hpp"
class AgentSpawner : public ScriptableSystem<AgentSpawner>
{
public:
    explicit AgentSpawner() : ScriptableSystem("AgentSpawner") {}
};
#endif