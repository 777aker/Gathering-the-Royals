#include "font.hpp"

namespace dbbe
{
    Text::Text(lve::LveDevice &device, std::string text, float size, glm::vec2 position, glm::vec3 color)
    {
        for (long unsigned int i = 0; i < text.length(); i++)
        {
            auto tempChar = lve::LveGameObject::createGameObject();
            tempChar.transform2d.scale = {size, size};
            tempChar.transform2d.translation = position;
            tempChar.color = color;
            tempChar.model = createCharModel(device, text[i]);
            charObjects.push_back(std::move(tempChar));
            position.x += size * letterSpacing;
        }
    }

    Text::~Text()
    {
    }

    void Text::renderText(dbbe::RenderSystem &renderer, VkCommandBuffer commandBuffer)
    {
        renderer.renderGameObjects(commandBuffer, charObjects);
    }

    std::unique_ptr<lve::LveModel> Text::createCharModel(lve::LveDevice &device, char c)
    {
    }
}