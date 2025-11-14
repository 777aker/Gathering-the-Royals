#pragma once

#include "lve/lve_device.hpp"
#include "lve/lve_game_object.hpp"
#include "lve/lve_pipeline.hpp"

#include <memory>
#include <vector>

namespace dbbe
{
    class RenderSystem
    {
    public:
        RenderSystem(lve::LveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
        ~RenderSystem();

        RenderSystem(const RenderSystem &) = delete;
        RenderSystem &operator=(const RenderSystem &) = delete;

        void beginRender(VkCommandBuffer commandBuffer, VkDescriptorSet &descriptorSet);
        void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<lve::LveGameObject> &gameObjects);

    private:
        void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
        void createPipeline(VkRenderPass renderPass);

        lve::LveDevice &lveDevice;

        std::unique_ptr<lve::LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
    };
}