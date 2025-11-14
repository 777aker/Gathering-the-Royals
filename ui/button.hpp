#pragma once

#include "dbbe/engine.hpp"
#include "dbbe/colors.hpp"
#include "string"

class Button
{
public:
    Button(void (*call)(), double xpos, double ypos, std::string words, color fill);
    ~Button();
    bool clicked(double xpos, double ypos);
    void draw_button();

private:
    void (*call)();
    double xpos;
    double ypos;
    double width;
    double height;
    color fill;
    std::string words;
};