#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

struct Position {
    float x = 0.f;
    float y = 0.f;
};

struct Origin {
    float offsetX = 0.f;
    float offsetY = 0.f;
};

struct Angle {
    float degrees = 0.f;
    float rotation = 0.f;
};

struct Color {
    unsigned short r = 255;
    unsigned short g = 255;
    unsigned short b = 255;
    unsigned short a = 255;
};

struct RectangleProperties {
    float width = 50.f;
    float height = 50.f;
};

#endif //COMPONENTS_HPP
