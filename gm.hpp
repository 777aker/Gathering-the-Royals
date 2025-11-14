#pragma once

#include "lve/lve_device.hpp"
#include "lve/lve_game_object.hpp"
#include "lve/lve_renderer.hpp"
#include "lve/lve_window.hpp"
#include "lve/lve_descriptors.hpp"

#include <memory>
#include <vector>

namespace GTR
{
    class GameManager
    {
    public:
        enum GameStates
        {
            MAIN_MENU,
            FONT_EDITOR,
            UNIT_EDITOR
        };

        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        GameManager();
        ~GameManager();

        GameManager(const GameManager &) = delete;
        GameManager &operator=(const GameManager &) = delete;

        void run();

    private:
        enum GameStates gameState = MAIN_MENU;

        lve::LveWindow lveWindow{WIDTH, HEIGHT, "Vulkan Tutorial"};
        lve::LveDevice lveDevice{lveWindow};
        lve::LveRenderer lveRenderer{lveWindow, lveDevice};

        std::unique_ptr<lve::LveDescriptorPool> globalPool{};
        std::vector<lve::LveGameObject> gameObjects;
    };
}