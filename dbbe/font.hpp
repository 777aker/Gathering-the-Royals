#pragma once

#include "renderer.hpp"

#include "lve/lve_model.hpp"
#include "lve/lve_game_object.hpp"

#include <string>
#include <memory>

namespace dbbe
{
    class Text
    {
    public:
        Text(lve::LveDevice &device, std::string text, float size, glm::vec2 position, glm::vec3 color);
        ~Text();

        Text(const Text &) = delete;
        Text &operator=(const Text &) = delete;

        void renderText(dbbe::RenderSystem &renderer, VkCommandBuffer commandBuffer);

    private:
        float letterSpacing = 0.2;
        std::vector<lve::LveGameObject> charObjects{};
        std::unique_ptr<lve::LveModel> createCharModel(lve::LveDevice &device, char c);
    };
}