cmake_minimum_required(VERSION 3.16)
project(economy)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/extlibs/SFML/include")
include_directories("${PROJECT_SOURCE_DIR}/extlibs/imgui")
include_directories("${PROJECT_SOURCE_DIR}/extlibs/imgui-sfml")
include_directories("${PROJECT_SOURCE_DIR}/extlibs/implot")
include_directories("${PROJECT_SOURCE_DIR}/extlibs/ChaiScript/include")
include_directories("${PROJECT_SOURCE_DIR}/extlibs/ChaiScript")

add_definitions(-DCHAISCRIPT_NO_THREADS)
add_definitions(-DCHAISCRIPT_NO_THREADS_WARNING)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS})


add_executable(economy extlibs/implot/implot.cpp extlibs/implot/implot_items.cpp extlibs/imgui/imgui.cpp extlibs/imgui/imgui_widgets.cpp extlibs/imgui/imgui_draw.cpp extlibs/imgui/imgui_tables.cpp extlibs/imgui-sfml/imgui-SFML.cpp src/main.cpp src/systems/OfferCreator.cpp src/systems/AgentConsoleDisplayer.cpp src/systems/AgentSpawner.cpp src/systems/MarketResolver.cpp src/systems/CurrencyCreator.cpp src/components/Product.cpp include/Utils.hpp include/systems/MarketResolver.hpp include/systems/AgentSpawner.hpp include/systems/AgentConsoleDisplayer.hpp include/systems/OfferCreator.hpp include/components/Agent.hpp include/components/Offer.hpp include/Common.hpp include/components/Product.hpp include/components/Demand.hpp include/Application.hpp src/Application.cpp src/components/Agent.cpp include/systems/AgentGuiDisplayer.hpp src/systems/AgentGuiDisplayer.cpp)
link_directories("/usr/local/lib")
target_link_libraries(economy entityx)
target_link_libraries(economy sfml-graphics)
target_link_libraries(economy sfml-window)
target_link_libraries(economy sfml-network)
target_link_libraries(economy sfml-system)

target_link_libraries(economy ${OPENGL_LIBRARIES})
target_link_libraries(economy dl)