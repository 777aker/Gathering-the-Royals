#include "models.hpp"

namespace dbbe
{
    std::unique_ptr<lve::LveModel> createSquareModel(lve::LveDevice &device)
    {
        std::vector<lve::LveModel::Vertex> vertices = {
            {{-0.5f, -0.5f}},
            {{0.5f, 0.5f}},
            {{-0.5f, 0.5f}},
            {{-0.5f, -0.5f}},
            {{0.5f, -0.5f}},
            {{0.5f, 0.5f}},
        };
        return std::make_unique<lve::LveModel>(device, vertices);
    }
}