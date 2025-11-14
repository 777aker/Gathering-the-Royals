#pragma once

#include "lve/lve_model.hpp"
#include "lve/lve_device.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <memory>

namespace dbbe
{
    std::unique_ptr<lve::LveModel> createSquareModel(lve::LveDevice &device);
}