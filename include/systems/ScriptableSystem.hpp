//
// Created by dwarf on 11/04/2021.
//

#ifndef ECONOMY_SCRIPTABLESYSTEM_HPP
#define ECONOMY_SCRIPTABLESYSTEM_HPP
#include "../Common.hpp"
#include "../Utils.hpp"
#include "../components/Agent.hpp"
template<class SUBSYSTEM>
class ScriptableSystem : public entityx::System<SUBSYSTEM>
{
public:
    explicit ScriptableSystem(const std::string& pDirectoryName = "default") : mDirectoryName(pDirectoryName){}
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
    {
        mChai.eval_file("scripts/"+mDirectoryName+"/update.chai");
    }
    void configure(entityx::EntityManager &es, entityx::EventManager &events)
    {
        mChai.add(chaiscript::var(&es),"economy");

        mChai.add(chaiscript::fun(&Utils::randomBetween),"randomBetween");

        mChai.add(chaiscript::fun(&Agent::addCurrency),"addCurrency");

        mChai.add(chaiscript::fun(&entityx::EntityManager::each<Agent>),"forEachAgent");
        mChai.add(chaiscript::fun(&entityx::EntityManager::create),"createAgent");

        mChai.eval_file("scripts/"+mDirectoryName+"/configure.chai");
    }

private:
    chaiscript::ChaiScript mChai;
    const std::string mDirectoryName;

};
#endif //ECONOMY_SCRIPTABLESYSTEM_HPP
