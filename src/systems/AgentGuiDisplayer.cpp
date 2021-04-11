//
// Created by dwarf on 01/04/2021.
//
#include "../../include/systems/AgentGuiDisplayer.hpp"

void AgentGuiDisplayer::configure(entityx::EntityManager &es, entityx::EventManager &events) {
    es.each<Agent>([this](entityx::Entity entity, Agent &agent)
    {
        mCurrencyByAgent[agent.getId()] = std::vector<double>(100);
    });
}

void AgentGuiDisplayer::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) {

    double totalCurrencies = 0;

    es.each<Agent>([this, &totalCurrencies](entityx::Entity entity, Agent &agent) {
        totalCurrencies += agent.getCurrencies();
        mCurrencyByAgent[agent.getId()][mCurrentPlot] = agent.getCurrencies();
    });

    mTotalCurrencies[mCurrentPlot] = totalCurrencies;
    mXplot[mCurrentPlot] = mCurrentPlot;

    mCurrentPlot = (mCurrentPlot + 1) % 100;

    ImGui::Begin("Economy");
    ImPlot::SetNextPlotLimits(0, 100, 0, 1000);
    ImPlot::BeginPlot("Currencies", "Iteration", "Amount");
    ImPlot::PlotShaded("Total", mXplot, mTotalCurrencies, 100, 0);

    for (auto agentcurrency : mCurrencyByAgent) {
        double *arr = &agentcurrency.second[0];
        ImPlot::PlotShaded(std::to_string(agentcurrency.first).c_str(), mXplot, arr, 100, 0);
    }

    ImPlot::EndPlot();
    ImGui::End();
}
