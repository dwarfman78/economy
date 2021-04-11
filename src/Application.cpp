//
// Created by dwarf on 28/02/2021.
//
#include "../include/Application.hpp"
#include "../include/systems/AgentSpawner.hpp"
#include "../include/systems/AgentConsoleDisplayer.hpp"
#include "../include/systems/OfferCreator.hpp"
#include "../include/systems/MarketResolver.hpp"
#include "../include/systems/CurrencyCreator.hpp"
#include "../include/systems/AgentGuiDisplayer.hpp"
Application::Application()
{
    // System order is important !
    systems.add<AgentGuiDisplayer>();
    systems.add<AgentConsoleDisplayer>();
    systems.add<MarketResolver>();
    systems.add<CurrencyCreator>();
    systems.add<OfferCreator>();
    systems.add<AgentSpawner>();
    // !!!!!!!!!!!!!!!!!!!!!!!!!!

    systems.configure();
}

void Application::start() {

    std::cout << "Application started !" << std::endl;

    sf::RenderWindow window(sf::VideoMode(640, 480), "Economy");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    ImPlot::CreateContext();

    {
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 5.3f;
        style.FrameRounding = 2.3f;
        style.ScrollbarRounding = 0;
    }

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time dt = deltaClock.restart();
        ImGui::SFML::Update(window, dt);

        systems.update<AgentSpawner>(dt.asMilliseconds());
        systems.update<CurrencyCreator>(dt.asMilliseconds());
        systems.update<OfferCreator>(dt.asMilliseconds());
        //systems.update<AgentConsoleDisplayer>(dt.asMilliseconds());
        systems.update<MarketResolver>(dt.asMilliseconds());
        systems.update<AgentGuiDisplayer>(dt.asMilliseconds());

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

}

