#include "gm.hpp"

#include "dbbe/renderer.hpp"
#include "dbbe/models.hpp"
#include "lve/lve_buffer.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <chrono>

struct GlobalUbo
{
    glm::vec2 projectionVector;
};

namespace GTR
{
    GameManager::GameManager()
    {
        globalPool = lve::LveDescriptorPool::Builder(lveDevice)
                         .setMaxSets(lveRenderer.getImageCount())
                         .addPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, lveRenderer.getImageCount())
                         .build();
    }
    GameManager::~GameManager() {}

    void GameManager::run()
    {
        std::vector<std::unique_ptr<lve::LveBuffer>> uboBuffers(lveRenderer.getImageCount());
        for (long unsigned int i = 0; i < uboBuffers.size(); i++)
        {
            uboBuffers[i] = std::make_unique<lve::LveBuffer>(
                lveDevice,
                sizeof(GlobalUbo),
                1,
                VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
            uboBuffers[i]->map();
        }

        auto globalSetLayout = lve::LveDescriptorSetLayout::Builder(lveDevice)
                                   .addBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT)
                                   .build();

        std::vector<VkDescriptorSet> globalDescriptorSets(lveRenderer.getImageCount());
        for (long unsigned int i = 0; i < globalDescriptorSets.size(); i++)
        {
            auto bufferInfo = uboBuffers[i]->descriptorInfo();
            lve::LveDescriptorWriter(*globalSetLayout, *globalPool)
                .writeBuffer(0, &bufferInfo)
                .build(globalDescriptorSets[i]);
        }

        dbbe::RenderSystem renderSystem{lveDevice, lveRenderer.getSwapChainRenderPass(), globalSetLayout->getDescriptorSetLayout()};

        std::shared_ptr<lve::LveModel> squareModel = dbbe::createSquareModel(lveDevice);

        std::vector<lve::LveGameObject> renderObjects{};
        auto test_point_1 = lve::LveGameObject::createGameObject();
        test_point_1.transform2d.scale = {0.1f, 0.1f};
        test_point_1.color = {0.5f, 0.0f, 0.0f};
        test_point_1.model = squareModel;
        renderObjects.push_back(std::move(test_point_1));
        auto test_point_2 = lve::LveGameObject::createGameObject();
        test_point_2.transform2d.scale = {0.3f, 0.3f};
        test_point_2.color = {0.0f, 0.5f, 0.2f};
        test_point_2.model = squareModel;
        test_point_2.transform2d.translation = {0.8f, -0.4f};
        renderObjects.push_back(std::move(test_point_2));

        // init main menu

        auto currentTime = std::chrono::high_resolution_clock::now();

        while (!lveWindow.shouldClose())
        {
            glfwPollEvents();

            auto newTime = std::chrono::high_resolution_clock::now();
            float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
            currentTime = newTime;

            if (auto commandBuffer = lveRenderer.beginFrame())
            {
                // update ubo
                GlobalUbo ubo{};
                float aspectRatio = lveRenderer.getAspectRatio();
                ubo.projectionVector = {1.0f / aspectRatio, 1.0f};
                uboBuffers[lveRenderer.getFrameIndex()]->writeToBuffer(&ubo);
                // render
                lveRenderer.beginSwapChainRenderPass(commandBuffer);
                renderSystem.beginRender(commandBuffer, globalDescriptorSets[lveRenderer.getFrameIndex()]);
                // switch based on game state and call that class's renderer
                renderSystem.renderGameObjects(commandBuffer, renderObjects);
                lveRenderer.endSwapChainRenderPass(commandBuffer);
                lveRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(lveDevice.device());
    }
}